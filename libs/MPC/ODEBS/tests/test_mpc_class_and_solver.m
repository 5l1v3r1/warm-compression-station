
for k=1:100
    nz = 100;
    H = (rand(nz)-0.5)^7; H = H*H'+10*eye(nz) ; chol(H);
    % H = full(sprand(nz,nz,.1)); H = H*H'+1*eye(nz); chol(H);
    h = flipud(H(:,3));
    Gamma = 1*(rand(round(2*nz),nz)-0.5);
    g = 1*rand(round(2*nz),1);
    lb = -1e150*ones(nz,1);
    ub = -lb;

    z_0 = (-H\h);
    st = 200;

    tic, [z1 iter1 lambda1] = solve_pb_mpc_m(H,Gamma,h,g,lb,ub,[],[],[],[],[],[],st,z_0); toc
    tic, [z2,fval,exitflag,iter2,lambda2] = qpOASES(H,h,Gamma,lb,ub,[],g,z_0); toc

    figure(4),semilogy(G), grid on
    figure(5),plot(Gamma*z1(:,end)-g), hold all, plot(Gamma*z2-g), hold off
    figure(8),plot(z1(:,end)), hold all, plot(z2), hold off
    
    max(eig(H))
    max(lambda1)

    [z3,fval3,exitflag3,iter3,lambda3] = qpOASES(H,h,Gamma,lb,ub,[],g,z1);
    
    if G(end)>10^12
        break
    end
    
    pause(0.5)
end


