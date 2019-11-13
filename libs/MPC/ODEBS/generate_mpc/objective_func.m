function [ mpc ] = objective_func( mpc )

% modèle
A = mpc.M.Ad; B = mpc.M.Bd; C = mpc.M.Cd; F = mpc.M.Fd; % C_sp = mpc.M.C_sp;

% paramétrisation
Np = mpc.Np; id = mpc.i.id; it = mpc.i.it; ip = mpc.i.ip; iv = mpc.i.iv;

% nombre d'entré / sortie / états
ns = length(A); % number of states 
nu = size(B,2); % number of control efforts
ny = size(C,1); % number of weigthed output
nd = size(F,2); % number of disturbances sources 

% poids
Q = mpc.W.Q; % state weigth
R = mpc.W.R; % actuator weigth

% poids des contraintes softs
S_u_p = mpc.csrt.soft.u_max(mpc.csrt.soft.u_max<inf);
S_u_m = mpc.csrt.soft.u_min(mpc.csrt.soft.u_min<inf);

S_du_p = mpc.csrt.soft.du_max(mpc.csrt.soft.du_max<inf);
S_du_m = mpc.csrt.soft.du_min(mpc.csrt.soft.du_min<inf);

S_y_p = mpc.csrt.soft.y_max(mpc.csrt.soft.y_max<inf);
S_y_m = mpc.csrt.soft.y_min(mpc.csrt.soft.y_min<inf);

%vecteur de poids de contraintes soft
R_soft = [S_y_p; S_y_m; S_du_p; S_du_m; S_u_p; S_u_m];

%nombre de contraintes softs
n_soft = numel(R_soft);
            
if strcmp(mpc.solver,'ode-based')
    nu_new = size(B,2);
elseif strcmp(mpc.solver,'active-set')
    R = blkdiag(R,diag(R_soft));
    B = [B zeros(ns,n_soft)];
    nu_new = size(B,2);
else
    error('you have to choose beetwen ''ode-based'' solver or ''active-set'' solver');
end

Phi_x = zeros(ns*Np,nu_new*Np);
Phi_y = zeros(ns*Np,nu_new*Np);
Psi = zeros(ns*Np,ns);
Theta = zeros(ns*Np,nd*Np);

Grand_Q = Q;
Grand_R = R;

for i=1:Np
    try
        Phi_x((i-1)*ny+1:i*ny,1:i*nu_new) =...
            [C*A^(i-1)*B Phi_x((i-2)*ny+1:(i-1)*ny,1:(i-1)*nu_new)];
        Phi_y((i-1)*ny+1:i*ny,1:i*nu_new) =...
            [C*A^(i-1)*B Phi_y((i-2)*ny+1:(i-1)*ny,1:(i-1)*nu_new)];
        Theta((i-1)*ny+1:i*ny,1:i*nd) =...
            [C*A^(i-1)*F Theta((i-2)*ny+1:(i-1)*ny,1:(i-1)*nd)];
        Psi((i-1)*ny+1:i*ny,:) =...
            Psi((i-2)*ny+1:(i-1)*ny,:)*A;
        Grand_Q = blkdiag(Grand_Q,Q);
        Grand_R = blkdiag(Grand_R,R);
    catch
        Phi_y((i-1)*ny+1:i*ny,1:i*nu_new) = C*A^(i-1)*B;
        Phi_x((i-1)*ny+1:i*ny,1:i*nu_new) = C*A^(i-1)*B;
        Theta((i-1)*ny+1:i*ny,1:i*nd) = C*A^(i-1)*F;
        Psi((i-1)*ny+1:i*ny,:) = C*A^i; 
    end
end

% csrt = [mpc.csrt.yc_min; mpc.csrt.yc_max; mpc.csrt.du_min; mpc.csrt.du_max] ;
% ncp = numel(csrt);
% Pi_iv = select_instants(Np,ncp,iv); % matrice de vérif cst

[mpc.Pi.Pi_z, mpc.i.sel_id] = parametrize(nu_new,Np,id); % matrice de décision
[mpc.Pi.Pi_it, mpc.i.sel_it] = parametrize(ny,Np,it); % matrice de param trajectoire
[mpc.Pi.Pi_ip, mpc.i.sel_ip] = parametrize(nd,Np,ip); % matrice de param pred perturb
[mpc.Pi.Pi_ite, mpc.i.sel_ite] = parametrize(nu_new,Np,1); % matrice de param trajectoire entrée

mpc.pb.H = mpc.Pi.Pi_z'*Phi_x'*Grand_Q*Phi_x*mpc.Pi.Pi_z + ...
           mpc.Pi.Pi_z'*eye(nu_new*Np)'*Grand_R*eye(nu_new*Np)*mpc.Pi.Pi_z;
mpc.pb.H = (mpc.pb.H+mpc.pb.H')/2;
mpc.pb.F1 = mpc.Pi.Pi_z'*Phi_x'*Grand_Q*Psi;
mpc.pb.F2 = - mpc.Pi.Pi_z'*Phi_y'*Grand_Q*eye(Np*ny)*mpc.Pi.Pi_it;
mpc.pb.F3 = mpc.Pi.Pi_z'*Phi_x'*Grand_Q*Theta*mpc.Pi.Pi_ip;
mpc.pb.F4 = -mpc.Pi.Pi_z'*Grand_R*mpc.Pi.Pi_ite;

% nombre d'entré / sortie / états
mpc.N.ns = ns; % number of states 
mpc.N.nu = nu; % number of control efforts
mpc.N.ny = ny; % number of weigthed output
mpc.N.nd = nd; % number of disturbances sources 
mpc.N.n_soft = n_soft; % nombre de contraintes softs
% mpc.N.ny_sp = ny; % number of weigthed output


