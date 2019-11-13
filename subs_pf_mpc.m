function [u_t, w_t, x_t, y_ref_t, u_ref_t] = subs_pf_mpc(u,w,x,y_ref,mpc)

    u_t = u - mpc.pf.u_0; 
    w_t = w - mpc.pf.w_0;
    x_t = x ;
    y_ref_t = y_ref ;

    u_ref_t = zeros(3,1);

end