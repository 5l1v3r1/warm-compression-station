function [u_t, w_t, x_t, y_ref_t, u_ref_t] = subs_pf_mpc(u,w,x,y_ref,mpc)

    u_t = u - mpc.pf.u_0; 
    w_t = w - mpc.pf.w_0;
    x_t = x - mpc.pf.x_0;
    y_ref_t = y_ref - mpc.pf.x_0;
%     u_ref_t = zeros(2,1);
    u_ref_t = ([max(w) max(w(1)-w(2),0) max(w(2)-w(1),0)]' - mpc.pf.u_0);

end