
clear all
close all

nzp = round(logspace(1,2.699,10));
softener = 1e-6;


for j=10:length(nzp)
    nz = nzp(j);
    for i=1:40

        clear functions

        H = (rand(nz)-0.5)^3; H = H*H'+10*eye(nz); chol(H);
        h = flipud(H(:,3));
        Gamma = rand(round(2*nz),nz)-0.5;
        g = rand(round(2*nz),1);
        lb = -10000000*ones(nz,1);
        ub = -lb;

        z_0 = -H\h;
        solve_pb_mpc(H,Gamma); %init mpc problem with H and Gamma
        f = @(t,z)djdp(t,z,H,h,Gamma,g,max(eig(H))*1e6,softener);
        opt = odeset('RelTol',0.001,'AbsTol',0.0001,'MaxStep',1e12,'InitialStep',1e5);
        
        nk=4;
        if nz>200
            nk=3;
        end
        if nz>400
            nk=2;
        end
        clear a b c
        for k=1:nk
            tic, [z,fval,exitflag,iter1,lambda] = qpOASES(H,h,Gamma,lb,ub,[],g,z_0); a(k)=toc;
            tic, [z_us G iterode] = solve_pb_mpc(h,g,lb,ub,z_0,2000); b(k) = toc;  %solve pb
%             tic, [ttt, z_ode] = ode15s(f,[0 10^12],z_0,opt); c(k) = toc;
        end
        iter1_p(i,j) = iter1;
        [z2,fval,exitflag,iter2,lambda] = qpOASES(H,h,Gamma,lb,ub,[],g,z_us);
        iter2_p(i,j) = iter2;
        iterode_p(i,j) = iterode;
        
        difference(i,j) = sum(abs(z_us-z));
        
        timeoasis(i,j) = min(a); timeodeperso(i,j) = min(b); %timeodepmat(i,j) = min(c);

        maxil(j,i) = max(Gamma*z_us(:,end)-g);
        maxeig(j,i) = max(eig(H));
        condH(j,i) = cond(H);
        minG(j,i) = min(G);
        
        if (sum(abs(z_us-z))/nz)>.1
            disp('toto');
        end
        
        figure(6)
        semilogy(G)
    end
    figure(7)
    subplot(311)
    semilogy(nzp(1:j),mean(timeodeperso),nzp(1:j),mean(timeoasis))
    ylabel('Temps de résolution')
    xlabel('taille du probleme')
    legend('qpOASIS','ode based solver','Location','southeast')
    grid on
    
    subplot(312)
    semilogy(nzp(1:j),mean(maxeig'))
    ylabel('Plus grande valeur propre')
    xlabel('taille du probleme')
    grid on

    subplot(313)
    plot(nzp(1:j),mean(maxil'))
    ylabel('dépassement de contrainte max')   
    xlabel('taille du probleme')
    grid on

    pause(1)
    j
end





