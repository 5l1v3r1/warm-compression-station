nz = 20;
H = (rand(nz)-0.5)^3; 
H = sprand(nz,nz,0.05);
H = H*H'+10*eye(nz); chol(H);
H = full(H);
h = flipud(H(:,3));
Gamma = rand(round(2*nz),nz)-0.5;
g = rand(round(2*nz),1);
lb = -1e0*ones(nz,1);
ub = -lb;
rho_ind = [1 2 3]';
rho = [1e12 1e12 1e12]';
st = 100;
z_0 = -H\h;

alpha = ones(size(g));
alpha_min = ones(size(lb));
alpha_max = ones(size(ub));


Hp1 = denom(H,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,12,z_0);
Hp2 = denom_mex(H,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,12,z_0);

sum(sum(abs(Hp1-Hp2)))

G1 = djdp(H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,z_0);
G2 = djdp_mex(H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,z_0);
sum(sum(abs(G1-G2)))

delta1 = lins_perso(Hp1,G1);
delta2 = lins_perso_mex(Hp2,G2);

sum(sum(abs(delta1-delta2)))


tic, for i=1:1000, delta1 = lins_perso(denom(H,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,12,z_0)...
        ,djdp(H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,z_0)); end; toc

tic, for i=1:1000, delta2 = test_num_den_solve(H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,12,z_0); end,  toc

norm(delta1-delta2)



