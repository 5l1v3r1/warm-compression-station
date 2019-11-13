function mpc = cstr_func(mpc)

% modèle
A = mpc.M.Ad; B = mpc.M.Bd; F = mpc.M.Fd;

% paramétrisation
Np = mpc.Np; id = mpc.i.id; it = mpc.i.it; ip = mpc.i.ip; iv = mpc.i.iv;

% vecteurs de paramétrisation
n_id = length(id); n_iv = length(iv); n_ip = length(ip); 

% contraintes soft
s_u_p = mpc.csrt.soft.u_max<inf;    s_u_m = mpc.csrt.soft.u_min<inf;    % u
s_du_p = mpc.csrt.soft.du_max<inf;  s_du_m = mpc.csrt.soft.du_min<inf;  % du
s_y_p =mpc.csrt.soft.y_max<inf;     s_y_m = mpc.csrt.soft.y_min<inf;    % y

% poids des contraintes softs
S_du_p = mpc.csrt.soft.du_max(s_du_p);  S_du_m = mpc.csrt.soft.du_min(s_du_m);  % du
S_u_p = mpc.csrt.soft.u_max(s_u_p);     S_u_m = mpc.csrt.soft.u_min(s_u_m);     % u
S_y_p = mpc.csrt.soft.y_max(s_y_p);     S_y_m = mpc.csrt.soft.y_min(s_y_m);     % y

% vecteur de poids de contraintes soft
R_soft = [S_y_p; S_y_m; S_du_p; S_du_m; S_u_p; S_u_m]; % y du u
ysoft = 1e9*ones(size([s_y_p; s_y_m]));
ysoft([s_y_p; s_y_m],:) = [S_y_p; S_y_m];

dusoft = 1e9*ones(size([s_du_p; s_du_m]));
dusoft([s_du_p; s_du_m],:) = [S_du_p; S_du_m];

%nombre de contraintes softs
n_soft = numel(R_soft);
             
% matrice de sorties des sorties contraintes
Ccmin = mpc.csrt.Cc_min; Ccmax = mpc.csrt.Cc_max; Cc = [Ccmax; -Ccmin];
Dcmin = mpc.csrt.Dc_min; Dcmax = mpc.csrt.Dc_max; Dc = [Dcmax; -Dcmin];
Gcmin = mpc.csrt.Gc_min; Gcmax = mpc.csrt.Gc_max; Gc = [Gcmax; -Gcmin];

% nombre d'entré / sortie / états
ns = length(A); % number of states 
nu = size(B,2); % number of control efforts
nyc = size([Cc Dc Gc],1); % number of output to constraint
nd = size(F,2);

% valeur des contraintes
yc_min = mpc.csrt.yc_min;    yc_max = mpc.csrt.yc_max;
du_min = mpc.csrt.du_min;    du_max = mpc.csrt.du_max;
u_min = mpc.csrt.u_min;      u_max = mpc.csrt.u_max;

% contraintes sur l'amplitude du vecteur de sortie
cstr_y = [yc_max; -yc_min];
s_y = [s_y_p; s_y_m];

% contraintes sur la dérivée du vecteur d'optimisation
cstr_du = [du_max; -du_min];
s_du = [s_du_p; s_du_m];

% contraintes sur l'amplitude du vecteur d'optimisation
cstr_u = [u_max; -u_min];
s_u = [s_u_p; s_u_m];

if strcmp(mpc.solver,'ode-based')
    nuv = size(B,2);
    Soft_du  = zeros(2*nu,0);
    
    % contraintes sur l'amplitude de u
    over_z_unit = [u_max]; % attention remplacer la contrainte 1e9 par la vraie.
    under_z_unit = [u_min];
        
    % relax des contraintes sur y
    Ysoft = reshape(ysoft*ones(1,n_iv),numel(ysoft)*n_iv,1);
    
    %relax des contraintes sur du
    DUsoft = reshape(dusoft*ones(1,n_id),numel(dusoft)*n_id,1);
    
elseif strcmp(mpc.solver,'active-set')
    B = [B zeros(ns,n_soft)];
    nuv = size(B,2);
    
    % mise à jour de la matrice D
    Soft_y = zeros(nyc,sum(s_y));
    Soft_y(s_y,:)  = eye(sum(s_y));
    Soft_y = [Soft_y zeros(length(s_y),sum([s_u;s_du]))];
    Dc = [Dc Soft_y];
    
    % génération de Soft_du
    Soft_du = zeros(2*nu,sum(s_du));
    Soft_du(s_du,:)  = eye(sum(s_du));
    Soft_du = [zeros(length(s_du),sum(s_y)) Soft_du zeros(length(s_du),sum(s_u))];
       
    % contraintes sur l'amplitude de u
    over_z_unit = [u_max; 1e9*ones(n_soft,1)]; % attention remplacer la contrainte 1e9 par la vraie.
    under_z_unit = [u_min; -1e9*ones(n_soft,1)];
else
    error('you have to choose beetwen ''ode-based'' solver or ''active-set'' solver');
end


% contraintes sur la sortie
Phi_plus = zeros(nyc*(Np+1),nuv*(Np+1));
Psi_plus = zeros(nyc*(Np+1),ns);
Theta_plus = zeros(nyc*(Np+1),nd*(Np+1));

i=1;
Phi_plus((i-1)*nyc+1:i*nyc,1:i*nuv) = Dc;
Theta_plus((i-1)*nyc+1:i*nyc,1:i*nd) = Gc;
Psi_plus((i-1)*nyc+1:i*nyc,:) = Cc;
gamma_y = cstr_y;

for i=2:Np+1
    Phi_plus((i-1)*nyc+1:i*nyc,1:i*nuv) = [Cc*A^(i-2)*B Phi_plus((i-2)*nyc+1:(i-1)*nyc,1:(i-1)*nuv)];
    Theta_plus((i-1)*nyc+1:i*nyc,1:i*nd) = [Cc*A^(i-2)*F Theta_plus((i-2)*nyc+1:(i-1)*nyc,1:(i-1)*nd)];
    Psi_plus((i-1)*nyc+1:i*nyc,:) = Psi_plus((i-2)*nyc+1:(i-1)*nyc,:)*A;
    gamma_y = [gamma_y; cstr_y];
end

Pi_r_u = parametrize(nuv,Np+1,1:Np);
Pi_r_w = parametrize(nd,Np+1,1:Np);

Phi_C = Phi_plus*Pi_r_u;
Psi_C = -Psi_plus;
Theta_C = -Theta_plus*Pi_r_w;

mpc.Pi.Pi_select = select_instants(Np+1,nyc,iv); % selection des cstr a respecter
Pi_z = parametrize(nuv,Np,id); % param du vecteur d'optimisation
Pi_ip = parametrize(nd,Np,ip); % param du vecteur de perturbation

Gamma_y = mpc.Pi.Pi_select*Phi_C*Pi_z;
gamma_xy = mpc.Pi.Pi_select*Psi_C;
gamma_wy = mpc.Pi.Pi_select*Theta_C*Pi_ip;
gamma_y = mpc.Pi.Pi_select*gamma_y;
% fin calcul contraintes sortie


% contraintes sur l'amplitude du vecteur de commande
over_z = zeros(nuv*n_id,1);
under_z = over_z;

for i=1:n_id
    ind = (i-1)*(nuv)+1:i*(nuv);
    over_z(ind,1) = over_z_unit;
    under_z(ind,1) = under_z_unit;
end
% fin contraintes sur l'amplitude du vecteur de commande

% contraintes sur la dérivée du vecteur d'optimisation
gamma_ud = [ -[-eye(nu); eye(nu)]; zeros(nu*2*(n_id-1),nu)];

Gamma_d = [];
gamma_d = [];
id = [0 id];
for i=1:n_id
    s = min(i-1,1); % 0 if i=1 else 1 
    I1 = [-eye(nu*s); +eye(nu*s)];
    I2 = [+eye(nu); -eye(nu)];
    Om = zeros(2*nu,(nuv-nu)*s);

    if i>1
        Od = zeros(2*nu,(i-2)*nuv);
        Of = [zeros(2*nu,nuv*(n_id-i))];

        Gamma_d = [Gamma_d; [Od I1 Om I2 Soft_du Of]];
        gamma_d = [gamma_d; cstr_du*(id(i+1)-id(i)) ];
    else
        Od = zeros(2*nu,(i-2)*nuv);
        Of = [zeros(2*nu,nuv*(n_id-i))];

        Gamma_d = [Gamma_d; [Od I1 Om  I2 Soft_du Of]];
        gamma_d = [gamma_d; cstr_du*(id(i+1)-id(i)) ];
    end
end
% fin des contraintes sur la dérivée du vecteur de commande

mpc.pb.Gamma = [Gamma_y; Gamma_d];
mpc.pb.gamma = [gamma_y; gamma_d];
mpc.pb.gamma_x = [gamma_xy; zeros(nu*2*n_id,ns)];
mpc.pb.gamma_u = [zeros(length(gamma_y),nu); gamma_ud];
mpc.pb.gama_w = [gamma_wy; zeros(nu*2*n_id,n_ip*nd)];

mpc.pb.over_z = over_z;
mpc.pb.under_z = under_z;

% mpc.pb.alpha = [Ysoft; DUsoft];
mpc.N.nd = nd;
mpc.N.nyc = nyc;

mpc.N.n_id = n_id;
mpc.N.n_iv = n_iv;
mpc.N.n_uv = nuv;



