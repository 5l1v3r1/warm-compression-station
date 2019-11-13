function CE = predicteur(sysl,Tp)

    CE.sys_pred = c2d(sysl,Tp);

    CE.pf.out_0 = [BT.out_0; JT.out_0];
    CE.pf.u_0 = [BT.u_0; JT.u_0];
    CE.pf.w_0 = [BT.y32_0; JT.y01_0; BT.w_0; JT.w_0];
    CE.pf.x_0 = [BT.x0; JT.x0];

    CE.M.A = CE.sys_pred.a;        CE.M.C = CE.sys_pred.c;
    CE.M.F = CE.sys_pred.b(:,1:8); CE.M.B = CE.sys_pred.b(:,9:end);
    CE.M.G = CE.sys_pred.d(:,1:8); CE.M.D = CE.sys_pred.d(:,9:end);
    
end