nz = 100;
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

tic, G1 = djdp(H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,z_0); toc
% G2 = djdp_cmp(H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,z_0);
tic, G3 = djdp_mex(H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,z_0); toc

norm(G1-G3)/length(H)