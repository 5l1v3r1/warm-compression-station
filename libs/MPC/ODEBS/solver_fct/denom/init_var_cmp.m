nz = 10;
H = (rand(nz)-0.5)^3; H = H*H'+10*eye(nz); chol(H);
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
Hp2 = denom_cmp(H,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,12,z_0);
norm(Hp1-Hp2)/(norm(Hp1))

Hp3 = denom_mex(H,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,12,z_0); 

norm(Hp1-(Hp3+Hp3'-diag(diag(Hp3))))/(norm(Hp3))

tic, for i=1:100000, Hp1 = denom(H,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,12,z_0); end, toc
tic, for i=1:100000, Hp3 = denom_mex(H,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,12,z_0); end, toc
