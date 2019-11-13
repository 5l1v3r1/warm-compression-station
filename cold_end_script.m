clear all
Ts = 20;
load prm
ini = 1;

%% modèle du prédicteur
Tp = 5;
set_param('st400w_ce/Control','Commented','on');
op = findop('st400w_ce',1e4);
sysl = linearize('st400w_ce','st400w_ce/W400_ce',op);
sim('st400w_ce',1e4);

sys_pred = c2d(sysl,Tp);

mpc.pf.y_0 = y_simu(end,:)';
mpc.pf.u_0 = u_simu(end,:)';
mpc.pf.w_0 = w_simu(end,:)';

Ad = sys_pred.a;
Bd = sys_pred.b(:,length(mpc.pf.w_0)+1:length(mpc.pf.w_0)+length(mpc.pf.u_0));
Fd = sys_pred.b(:,1:length(mpc.pf.w_0)); 

Cd = sys_pred.c;
Dd = sys_pred.d(:,length(mpc.pf.w_0)+1:length(mpc.pf.w_0)+length(mpc.pf.u_0));
Gd = sys_pred.d(:,1:length(mpc.pf.w_0)); 

%% observateur
Ao = Ad;
Bo = Bd;
Fo = Fd;
Co = Cd;
Do = Dd;
Go = Gd;

Q = ones(length(Ao),1);
% Q = ones(length(Ao),1)./[abs(CE.pf.x_0); 1; 1];
% Q(20) = 0;
R = ones(size(Co,1),1);
% R = ones(size(C,1),1).*CE.pf.out_0(SEL);
% R(1) = 0.0001*R(1);
L = dlqr(Ao',Co',100*diag(Q),diag(R))';

Aoe = Ao-L*Co;
Boe = [Bo-L*Do Fo-L*Go L];
Coe = eye(length(Ao));
Doe = zeros(size(Coe*Boe));
% Coes = [Call Dall(:,9:10)];
% Does = [Dall];

%% CE.mpc Problem

% modèle et point de fonctionnement
mpc.Np = 100;
mpc.M.Ad = Ao; mpc.M.Bd = Bo;
mpc.M.Fd = Fo; mpc.M.Cd = eye(length(Ao));

% export des numéro de sortie pour les contraintes
mpc.csrt.y_LTB131 = 8; % bath level 
mpc.csrt.y_TTB130 = 2; % Turbine out temp 

% contrainte sur excursion moins des sorties
mpc.csrt.y_min = [mpc.csrt.y_TTB130 mpc.csrt.y_LTB131];
mpc.csrt.Cc_min = Co(mpc.csrt.y_min,:); 
mpc.csrt.Dc_min = Do(mpc.csrt.y_min,:);
mpc.csrt.Gc_min = Go(mpc.csrt.y_min,:);
mpc.csrt.soft.y_min = [1e5; 1e2]; % ttb130- est ferme, LTB131- est relaxée
mpc.csrt.yc_min = [-111.2 mpc.pf.y_0(mpc.csrt.y_LTB131)-3]'-mpc.pf.y_0(mpc.csrt.y_min);

% contrainte sur excursion plus des sorties
mpc.csrt.y_max = [mpc.csrt.y_TTB130 mpc.csrt.y_LTB131];
mpc.csrt.Cc_max = Co(mpc.csrt.y_max,:);
mpc.csrt.Dc_max = Do(mpc.csrt.y_max,:);
mpc.csrt.Gc_max = Go(mpc.csrt.y_max,:);
mpc.csrt.soft.y_max = [inf; 1e2]; % ttb130+ est relaxée, LTB131+ est relaxée
mpc.csrt.yc_max = [100 mpc.pf.y_0(mpc.csrt.y_LTB131)+3]'-mpc.pf.y_0(mpc.csrt.y_max);

% contrainte sur la pente actionneur descendente
mpc.csrt.du_min = [ -1 -12/60 -10]'*Tp;
mpc.csrt.soft.du_min = [1e4 inf inf]';

% contrainte sur la pente actionneur montante
mpc.csrt.du_max = [+1 +6/60  +10]'*Tp;  
mpc.csrt.soft.du_max = [inf inf inf]';

% contrainte sur l'amplitude basse actionneur
mpc.csrt.u_min = [15 10 0]'-mpc.pf.u_0; 
mpc.csrt.soft.u_min = [inf; inf; 1e8];

% contrainte sur l'amplitude haute actionneur
mpc.csrt.u_max = [60 60 150]'-mpc.pf.u_0;
mpc.csrt.soft.u_max = [inf; inf; inf];

% export des numéros de sortie pour les consignes
mpc.sp.y_TTB130 = 2; % Turbine out temp
mpc.sp.y_LTB131 = 8; % bath level 
mpc.sp.y = [mpc.csrt.y_TTB130 mpc.csrt.y_LTB131];
mpc.sp.Cc_max = Co(mpc.sp.y,:);
mpc.sp.Dc_max = Do(mpc.sp.y,:);
mpc.sp.Gc_max = Go(mpc.sp.y,:);

% important à remetre
% % matrice de pondérations
% tuyaux = strfind(sys_pred.StateName,'tuy');
% for i=1:length(tuyaux), Tuyaux(i) = ~isempty(tuyaux{i}); end
% q = [ones(1,19) 1 ones(1,8) 0 0]'./(abs([mpc.pf.x_0; 1; 1]));
% bainns1 = strfind(sys_pred.StateName,'ns1');
% for i=1:length(bainns1), Bainns1(i) = ~isempty(bainns1{i}); end
% a = find(Bainns1,10,'first');
% 
% q(Tuyaux(1:end)) = 0;    
% q(a(2)) = 0;
% q(a(1)) = 100*q(a(1));
% q(20) = 0;

% mpc.W.Q = 100*diag(q);
% mpc.W.R = diag([1 10 1 1e8 1e8]); % poids actionneurs

mpc.W.Q = 0.1*diag([ones(1,length(Ao)-6) 100 0 0 0 0 0]);
mpc.W.R = diag([1 1 100]); % poids actionneurs

% instants pour la paramétrisation
mpc.i.id = [1 2 4 8 16 50]; % instant de décisions
mpc.i.iv = [1 2 3 4 6 8 16 24 32 44 56 68 84 mpc.Np]; % instant de verification csrt out
mpc.i.it = [1]; % instant de trajectoire souhaitée
mpc.i.ip = [1]; % instant de prédiction perturb

% choix du solver pour la génération des matrices 
mpc.solver = 'active-set'; % 'active-set' or 'ode-based'
% mpc.solver = 'ode-based'; % 'active-set' or 'ode-based'

%% calcul du problème
mpc = objective_func(mpc);
% reste à faire : problème pour ode-based solver

mpc = cstr_func(mpc); % OK pour cstr soft 
% reste à faire : contraintes soft sur delta et u
% reste à faire : contrainte avec multiparamétrisation

%%
ini = 0;
set_param('st400w_ce/Control','Commented','off');

