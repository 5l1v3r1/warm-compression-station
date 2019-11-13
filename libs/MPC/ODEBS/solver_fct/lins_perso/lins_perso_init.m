nz = round(logspace(1,3,12));

for j=1:length(nz)
    H = (rand(nz(j))-0.5)^3; H = H*H'+10*eye(nz(j)); chol(H);
    h = flipud(H(:,3));
    Gamma = rand(round(2*nz(j)),nz(j))-0.5;
    g = rand(round(2*nz(j)),1);
    lb = -1e8*ones(nz(j),1);
    ub = -lb;
    rho_ind = [1 2 3]';
    rho = [1e12 1e12 1e12]';
    st = 100;
    z_0 = -H\h;

    d1 = lins_perso_cmp(H,h);
    d2 = lins_perso(H,h);
    d3 = lins_perso_mex(H,h);

    norm(d2-d3)/norm(d3)

    rep = max(1,round(1000*1000*100/(nz(j).^3)));
    tic, for i=1:rep, d2 = lins_perso(H,h); end, a = toc;
    tic, for i=1:rep, d3 = lins_perso_mex(H,h); end, b = toc;
    
    time_1(j) = (a)/rep;
    time_2(j) = (b)/rep;
    
end

semilogy(nz,time_1,nz,time_2,nz,.7*nz.^3/3*1e-9)

