function [mpc, u_t] = act_manu_mpc(manu, manu_val, mpc, u_t)

    for i=1:length(manu_val)
        if  (manu(i)==1)
            for j=1:mpc.N.n_id
                mpc.pb.over_z(i+(j-1)*mpc.N.n_uv,1) = manu_val(i)-mpc.pf.u_0(i);
                mpc.pb.under_z(i+(j-1)*mpc.N.n_uv,1) = manu_val(i)-mpc.pf.u_0(i);
            end
            u_t(i) = manu_val(i)-mpc.pf.u_0(i);
        end
    end

end