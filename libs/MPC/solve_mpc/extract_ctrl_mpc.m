function [u, infos] = extract_ctrl_mpc(z,u_t,infos,mpc)

    u_sol_t = max(min(z,mpc.pb.over_z),mpc.pb.under_z); 
    u(:,1) = max(min(u_sol_t(1:mpc.N.nu),u_t+mpc.csrt.du_max),mpc.csrt.du_min-u_t);

%     % projection et cout 
%     z = proj_u(u_sol,du_,mpc.lb,mpc.ub,B);
%     infos.J = cost_ol_k(z,dx,wref_pred,mpc);
% 
%     infos.cons1 = max(max([z-mpc.ub; mpc.lb-u_sol],0)); % bornes jaune
%     infos.cons2 = max(max(A(:,1:56)'*z-B(1:56)),0); % sorties magenta
%     infos.cons3 = max(max(A(:,57:end)'*z-B(57:end)),0); % delta cyan