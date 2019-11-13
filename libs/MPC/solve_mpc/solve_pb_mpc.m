function [p, infos] = solve_pb_mpc(Ni, z0, mpc)
    global truc
    if isempty(z0)
        p = zeros(length(mpc.pb.H),1);
    else
        p = z0;
    end
    
    if strcmp(mpc.solver,'ode-based') % Nous
        mpc.pb.alpha = 1e9*ones(size(mpc.pb.Gamma,1),1);
        mpc.pb.alpha_min = 1e9*ones(size(mpc.pb.under_z));
        mpc.pb.alpha_max = 1e9*ones(size(mpc.pb.over_z));
        mpc.pb.dt0 = 1;
         
        % H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,dt,z_0
        tic, [p, n, L, G] = ... 
                    solve_pb_mpc_c( mpc.pb.H, ... % H
                                    mpc.pb.h_vect, ... % h
                                    mpc.pb.Gamma, ... % A
                                    mpc.pb.gamma_vect, ... % ubA
                                    mpc.pb.under_z, ... % lb
                                    mpc.pb.over_z, ... % ub
                                    mpc.pb.alpha, ... % alpha
                                    mpc.pb.alpha_min, ... % alpha_min
                                    mpc.pb.alpha_max, ... % alpha_max
                                    Ni, ... % Nombre d'itérations maxi
                                    mpc.pb.dt0, ... % dt0
                                    p     ); a=toc;
                                
        infos.time = a;
        infos.G = G;
        infos.N = n;
        infos.Ncons = sum(L>=0);
        z_unc = -mpc.pb.H\mpc.pb.h_vect;
        infos.u_unc = z_unc(1:3);
        
        cst_act = sum (sum((mpc.pb.Gamma*p-mpc.pb.gamma_vect)>0) + sum((mpc.pb.under_z-p)>0) + sum((p-mpc.pb.over_z)>0));

    end
    
       
    if strcmp(mpc.solver,'active-set') % QPOASIS
        opt = qpOASES_options('maxIter',Ni);
        try
            tic, [p,fval,status,iter,lambda] = qpOASES_sequence('h', mpc.pb.h_vect,...% h
                                                                        mpc.pb.under_z, ... % lb
                                                                        mpc.pb.over_z, ... % ub
                                                                        [], ... % lbA
                                                                        mpc.pb.gamma_vect(1:end,:), ... % ubA
                                                                        opt ); a=toc;
           assert('caca',status == 0)
        catch
            tic, [p,fval,status,iter,lambda] = qpOASES_sequence('i', mpc.pb.H, ... % H
                                                                mpc.pb.h_vect, ... % h
                                                                mpc.pb.Gamma(1:end,:), ... % A
                                                                mpc.pb.under_z, ... % lb
                                                                mpc.pb.over_z, ... % ub
                                                                [], ... % lbA
                                                                mpc.pb.gamma_vect(1:end,:), ... % ubA
                                                                p, opt ); a=toc;
        end
        truc = [truc status];
        
        infos.time = a;
        infos.G = 0; 
        infos.N = iter;
        z_unc = -mpc.pb.H\mpc.pb.h_vect;
        infos.Ncons = sum(abs(lambda)>0);
        infos.u_unc = z_unc(1:3);
    end
    
%     if strcmp(mpc.solver,'pure-gradient') % QPOASIS
% 
%         tic, [p, info, les_J, les_nG, les_p] = pure_G(p,f1,lb,ub,B,Ni);  a  = toc;
% 
%         A = A';
%         infos.time = a;
%         infos.G = info(1); 
%         infos.N = info(6);
%         infos.les_J = les_J(1:infos.N);
%         [n i] = min(les_nG(1:infos.N));
%         infos.les_nG = les_nG;
% %         les_p = reshape(les_p,49,length(les_p)/49);
% %         p = les_p(:,i);
%         infos.G = infos.les_nG(i);
%         infos.Ncons = sum((A*p-B)>=0)+sum(([p-ub; lb-p]>=0));
%     end

return
