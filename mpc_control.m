function out = mpc_control(in,mpc)

% récupération des valeurs d'entrée
[u, w, x, y_ref, manu, manu_val, cstr_val, cstr_rho, z] = recup_in_mpc(in,mpc.N);

% soustraction du point de fonctionnement % manque u_ref
[u_t, w_t, x_t, y_ref_t, u_ref_t] = subs_pf_mpc(u,w,x,y_ref,mpc);

% mise a jour des valeurs de contraintes 
mpc = csrt_val_maj_mpc(cstr_val,mpc);

% mise a jour des pondérations de contraintes 
% fonctionnalité pour plus tard
% mpc = csrt_rho_maj_mpc(cstr_rho,mpc);

% prise en main actionneur
[mpc, u_t] = act_manu_mpc(manu, manu_val, mpc, u_t);

% définition pb mpc à résoudre
mpc = def_pb_mpc(u_t,w_t,x_t,y_ref_t,u_ref_t,mpc);

% résolution du problème
Ni = 1000;
% send_data
% while(read(bit_en_question==0));
% z = read_data;
[z, infos] = solve_pb_mpc(Ni, z, mpc);

% test = 0;
% norm(z(1:3)-u_ref_t)
% % ip = '132.168.11.42';
% ip = '127.0.0.1';
% if test==1 %132.168.11.42
%     lect_ecr(1400,1,1,ip);
%     lect_ecr(1000,60,[u; w; x; y_ref; manu; manu_val; cstr_val],ip);
% %     lect_ecr(1120,9,mpc.pb.h_vect,ip);
%     pause(0.005);
%     lect_ecr(1400,1,0,ip);
% 
%     z1 = lect_ecr(1520,9,ip);
%     if norm(z-z1)>0.001
%         disp('difference chelou...')
%         pause(0.20);
%         z1 = lect_ecr(1520,9,ip);
%         if norm(z-z1)>0.001
%             disp('difference très chelou...')
%             [z z1]
%         end
%     end
% end

u_t = z(1:3);

u = u_t + mpc.pf.u_0;
infos.cons1=0;
infos.cons2=0;
infos.cons3=0;
infos.J=0;

out = [	u;...
        infos.cons1;...
        infos.cons2;...
        infos.cons3;...
        log10(infos.G+1);...
        infos.N;...
        infos.time;...
        infos.Ncons;...
        z;...
        infos.u_unc];

    % p = mpc.Pi.Pi_z*z;
% p = reshape(p,8,length(p)/8);
% 
% x = x_t;
% for i=1:100
%     x(:,i+1) = mpc.M.Ad*x(:,i) + mpc.M.Bd*p(1:3,i) + mpc.M.Fd*w_t;
%     Y1(:,i) = mpc.csrt.Cc_max*x(:,i) + mpc.csrt.Dc_max*p(1:3,i) + mpc.csrt.Gc_max*w_t + mpc.pf.out_0(mpc.csrt.y_max);
% end
% 
% subplot(311)
% plot(Y1(2,:)')
% subplot(312)
% plot(p(1:8:end))
% subplot(313)
% plot(p(2:8:end))

% theta = [];
% for i=1:mpc.Np
%     theta = [theta; mpc.csrt.Cc_max*mpc.M.Ad^(i-1)];
%     if i>1
%         for j=1:i-1
%             phi((i-1)*3+1:i*3,(j-1)*3+1:j*3) = mpc.csrt.Cc_max*mpc.M.Ad^(i-j-1)*mpc.M.Bd;
%             psi((i-1)*3+1:i*3,(j-1)*8+1:j*8) = mpc.csrt.Cc_max*mpc.M.Ad^(i-j-1)*mpc.M.Fd;
%         end
%     end
%     j=i;
%     phi((i-1)*3+1:i*3,(j-1)*3+1:j*3) = mpc.csrt.Dc_max;
%     psi((i-1)*3+1:i*3,(j-1)*8+1:j*8) = mpc.csrt.Gc_max;
%     
% end
% 
% Y2 = theta*x_t + phi*reshape(u_t*ones(1,100),300,1) + psi*reshape(w_t*ones(1,100),800,1);
% Y2 = reshape(Y2,3,100);

% theta2 = [mpc.csrt.Cc_max*mpc.M.Ad^0; mpc.csrt.Cc_max*mpc.M.Ad^1; mpc.csrt.Cc_max*mpc.M.Ad^2; mpc.csrt.Cc_max*mpc.M.Ad^3; mpc.csrt.Cc_max*mpc.M.Ad^4; mpc.csrt.Cc_max*mpc.M.Ad^5];
% 
% phi2(1:3,1:6-3) = [mpc.csrt.Dc_max];
% phi2(4:6,1:9-3) = [mpc.csrt.Cc_max*mpc.M.Ad^0*mpc.M.Bd mpc.csrt.Dc_max  ];
% phi2(7:9,1:12-3) = [mpc.csrt.Cc_max*mpc.M.Ad^1*mpc.M.Bd mpc.csrt.Cc_max*mpc.M.Ad^0*mpc.M.Bd mpc.csrt.Dc_max  ];
% phi2(10:12,1:15-3) = [mpc.csrt.Cc_max*mpc.M.Ad^2*mpc.M.Bd mpc.csrt.Cc_max*mpc.M.Ad^1*mpc.M.Bd mpc.csrt.Cc_max*mpc.M.Ad^0*mpc.M.Bd mpc.csrt.Dc_max  ];
% phi2(13:15,1:18-3) = [mpc.csrt.Cc_max*mpc.M.Ad^3*mpc.M.Bd mpc.csrt.Cc_max*mpc.M.Ad^2*mpc.M.Bd mpc.csrt.Cc_max*mpc.M.Ad^1*mpc.M.Bd mpc.csrt.Cc_max*mpc.M.Ad^0*mpc.M.Bd mpc.csrt.Dc_max  ];
% phi2(16:18,1:21-3) = [mpc.csrt.Cc_max*mpc.M.Ad^4*mpc.M.Bd mpc.csrt.Cc_max*mpc.M.Ad^3*mpc.M.Bd mpc.csrt.Cc_max*mpc.M.Ad^2*mpc.M.Bd mpc.csrt.Cc_max*mpc.M.Ad^1*mpc.M.Bd mpc.csrt.Cc_max*mpc.M.Ad^0*mpc.M.Bd mpc.csrt.Dc_max  ];
% 
% psi2(1:3,1:16-8) = [mpc.csrt.Gc_max];
% psi2(4:6,1:24-8) = [mpc.csrt.Cc_max*mpc.M.Ad^0*mpc.M.Fd mpc.csrt.Gc_max  ];
% psi2(7:9,1:32-8) = [mpc.csrt.Cc_max*mpc.M.Ad^1*mpc.M.Fd mpc.csrt.Cc_max*mpc.M.Ad^0*mpc.M.Fd mpc.csrt.Gc_max  ];
% psi2(10:12,1:40-8) = [mpc.csrt.Cc_max*mpc.M.Ad^2*mpc.M.Fd mpc.csrt.Cc_max*mpc.M.Ad^1*mpc.M.Fd mpc.csrt.Cc_max*mpc.M.Ad^0*mpc.M.Fd mpc.csrt.Gc_max  ];
% psi2(13:15,1:48-8) = [mpc.csrt.Cc_max*mpc.M.Ad^3*mpc.M.Fd mpc.csrt.Cc_max*mpc.M.Ad^2*mpc.M.Fd mpc.csrt.Cc_max*mpc.M.Ad^1*mpc.M.Fd mpc.csrt.Cc_max*mpc.M.Ad^0*mpc.M.Fd mpc.csrt.Gc_max  ];
% psi2(16:18,1:56-8) = [mpc.csrt.Cc_max*mpc.M.Ad^5*mpc.M.Fd  mpc.csrt.Cc_max*mpc.M.Ad^3*mpc.M.Fd mpc.csrt.Cc_max*mpc.M.Ad^2*mpc.M.Fd mpc.csrt.Cc_max*mpc.M.Ad^1*mpc.M.Fd mpc.csrt.Cc_max*mpc.M.Ad^0*mpc.M.Fd mpc.csrt.Gc_max  ];
% 
% Y3 = theta2*x_t + phi2*[u_t; u_t; u_t; u_t; u_t; u_t] + psi2*[w_t; w_t; w_t; w_t; w_t; w_t]

% z = reshape([u_t; zeros(5,1)]*ones(1,10),80,1);
% ttt = mpc.pb.Gamma*z - mpc.pb.gamma_x*x_t + mpc.pb.gama_w*[w_t; w_t];

% figure(1)
% ytraj = mpc.pb.Gamma*z-mpc.pb.g+mpc.pb.gamma;
% plot(ytraj(1:4:56))
% % 
% figure(2)
% plot(z(1:10:end))
%          

% mpc.csrt.Cc_max*x_t + mpc.csrt.Dc_max*u_t + mpc.csrt.Gc_max*w_t    