function [p, G, i, lambda] = solve_pb_mpc_m(H,Gamma,h,g,lb,ub,...
                            alpha_ind,alpha_min_ind,alpha_max_ind,...
                            alpha,alpha_min,alpha_max,st,p)
% 
%     persistent mpc
    
%     if isempty(mpc)
    	mpc = ode_based_solver(H,Gamma,alpha_ind,alpha_min_ind,alpha_max_ind);
%     end
    
    mpc.maj(h,g,lb,ub,alpha,alpha_min,alpha_max);
    
%     tic, [p iter, lambda] = solve_pb_mpc(mpc.H,mpc.h,mpc.Gamma,mpc.g,mpc.lb,mpc.ub,...
%                 mpc.alpha,mpc.alpha_min,mpc.alpha_max,st,p); toc
%             
% end
    
    Newton = 1;
    mpc.dt = 1e-9;
    mpc.p = p;
    mpc.G = djdp_mex(mpc.H,mpc.h,mpc.Gamma,mpc.g,mpc.lb,mpc.ub,mpc.alpha,mpc.alpha_min,mpc.alpha_max,mpc.p); 

    G = zeros(1,st);

    for i=1:st

        mpc.ppl = mpc.p; % initialisation de ppl
        mpc.Gpl = mpc.G; % initialisation de Gpl
                    
        mpc.Hpl = denom_mex(mpc.H,mpc.Gamma,mpc.g,mpc.lb,mpc.ub,mpc.alpha,mpc.alpha_min,mpc.alpha_max,mpc.dt,mpc.ppl);

        for j=1:Newton
            mpc.num_pl_fct();
            mpc.delta_ppl = lins_perso_mex(mpc.Hpl,mpc.num_pl);
            mpc.saut_pl();
            mpc.Gpl = djdp_mex(mpc.H,mpc.h,mpc.Gamma,mpc.g,mpc.lb,mpc.ub,mpc.alpha,mpc.alpha_min,mpc.alpha_max,mpc.ppl);
        end

        mpc.ppu = mpc.ppl; % initialisation de ppu
        mpc.Gpu = mpc.Gpl; % initialisation de Gpu
        
        mpc.Hpu = denom_mex(mpc.H,mpc.Gamma,mpc.g,mpc.lb,mpc.ub,mpc.alpha,mpc.alpha_min,mpc.alpha_max,mpc.dt,mpc.ppu);

        for j=1:Newton        
            mpc.num_pu_fct();
            mpc.delta_ppu = lins_perso_mex(mpc.Hpu,mpc.num_pu);
            mpc.saut_pu();
            mpc.Gpu = djdp_mex(mpc.H,mpc.h,mpc.Gamma,mpc.g,mpc.lb,mpc.ub,mpc.alpha,mpc.alpha_min,mpc.alpha_max,mpc.ppu);
        end

        mpc.analyse();
        G(i) = norm(mpc.G);
        if max(mpc.ppu)>1e10 || max(-mpc.ppu)>1e10
            disp('caca ki pu')
        end 
        if norm((G(i)))<(10^3/mpc.REL_TOL/1e9)
            break; 
        end
                
    end
    p = mpc.ppu;
    lambda = mpc.Gamma*p-mpc.g;
      
end

% for i=1:1000
%     mpc.Hpl = denom(mpc.H,mpc.Gamma,mpc.g,mpc.lb,mpc.ub,mpc.alpha,mpc.alpha_min,mpc.alpha_max,mpc.dt,mpc.p);
%     mpc.Gpl = djdp(mpc.H,mpc.h,mpc.Gamma,mpc.g,mpc.lb,mpc.ub,mpc.alpha,mpc.alpha_min,mpc.alpha_max,mpc.p);
%     mpc.delta_ppl = linsolve(mpc.Hpl,mpc.dt*mpc.Gpl);
%     mpc.p = mpc.p + mpc.delta_ppl;
%     G(i) = norm(mpc.Gpl);
% 
%     V(i) = max(mpc.Gamma*mpc.p-mpc.g);
%     
%     Gplt = djdp(mpc.H,mpc.h,mpc.Gamma,mpc.g,mpc.lb,mpc.ub,mpc.alpha,mpc.alpha_min,mpc.alpha_max,mpc.p);
% 
%     r = norm(mpc.delta_ppl - mpc.dt*Gplt)^.5*mpc.dt*10000;
%     mpc.dt = mpc.dt*r^(-1/3);
% 
% end
%   p = mpc.p;
