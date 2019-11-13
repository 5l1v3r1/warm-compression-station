 close all
clear all

% modified triple integrator
ns = 3;
nu = 2;
nd = 2;

mpc.Ad = [1 0 0; 1 1 0; 0 1 1];
mpc.Bd = [1 0; 0 1; 0 0];
mpc.Cd = eye(ns);
mpc.Fd = [1 0; 0 0; 0 1];

mpc.C = [0 0 1];
mpc.D = [0 0];
mpc.G = [0 0];

mpc.Cc = [mpc.C;-mpc.C];
mpc.Dc = [mpc.D;-mpc.D];
mpc.Gc = [mpc.G;-mpc.G];

mpc.Np = 16;
mpc.id = [1 2 3 6];
mpc.iv = [1:1:8];
mpc.it = mpc.iv;
mpc.ip = mpc.iv;

mpc.QMPC = eye(ns)*500; % state weigth
mpc.RMPC = eye(2)/500; % actuator weigth
mpc.SMPC = eye(2); % difference weigth

mpc.yc_min = -[30];
mpc.yc_max = [30];

mpc.du_min = -[0.75; 1.5];
mpc.du_max = [0.75; 1.5];

mpc.u_min = -[3; 6];
mpc.u_max = [3; 6];

mpc.soft_u = [inf; inf];
mpc.soft_y = [inf; inf];

mpc.solver = 'active-set';
% mpc2 = compute_cost_quad(mpc);
tic, mpc = objective_func(mpc); toc
tic, mpc = cstr_func(mpc); toc

% test si pb est bien formulé (au niveau des tailles)
x0 = [0 0 0]';
Xref = reshape(x0*ones(1,length(mpc.it)),ns*length(mpc.it),1);
u0 = [0 0]';
w0 = [0 0]';
nd = size(mpc.Fd,2);
Wpred = reshape(w0*ones(1,length(mpc.ip)),nd*length(mpc.ip),1);
z_ref = [0 0]';
Zref = reshape(z_ref*ones(1,length(mpc.id)),2*length(mpc.id),1);

mpc.f = mpc.F1*x0 + mpc.F2*Xref + mpc.F3*Wpred + mpc.F4*Zref;
mpc.g = mpc.gamma + mpc.gamma_x*x0 + mpc.gamma_u*u0 + mpc.gama_w*Wpred;

[z,fval,exitflag,iter,lambda] = qpOASES(mpc.H,mpc.f,mpc.Gamma,mpc.under_z,mpc.over_z,[],mpc.g);

% simulation
clear x y d u

N_sim = 100;
t_sim = 1:N_sim;

[z,fval,exitflag,iter,lambda] = qpOASES(mpc.H,mpc.f,mpc.Gamma,mpc.under_z,mpc.over_z,[],mpc.g);

x_bo(:,1) = zeros(ns,1);
d(1,:) = [ones(1,N_sim/5)*0.75 ones(1,N_sim/5)*0.5 ones(1,N_sim/5)*0.25 -ones(1,N_sim/5)*0.33 ones(1,N_sim/5)*0];
d(2,:) = [ones(1,N_sim/5)*0.75 ones(1,N_sim/5)*0.5 -ones(1,N_sim/5)*0.33 -ones(1,N_sim/5)*0.33 ones(1,N_sim/5)*0];

for k=1:N_sim
    x_bo(:,k+1) = mpc.Ad*x_bo(:,k) + mpc.Fd*d(:,k) ;
    y_bo(:,k) = mpc.C*x_bo(:,k) + mpc.G*d(:,k);
end

x_bf(:,1) = zeros(ns,1);
u(:,1) = zeros(nu,1);
K = dlqr(mpc.Ad,mpc.Bd,mpc.QMPC,mpc.RMPC);
for k=1:N_sim
    x_bf(:,k+1) = mpc.Ad*x_bf(:,k) + mpc.Bd*u(:,k) + mpc.Fd*d(:,k);
    y_bf(:,k) = mpc.C*x_bf(:,k) + mpc.D*u(:,k) + mpc.G*d(:,k);
    
    Wpred = reshape(d(:,k)*ones(1,length(mpc.ip)),nd*length(mpc.ip),1);

    mpc.f = mpc.F1*x_bf(:,k+1) + mpc.F2*Xref + mpc.F3*Wpred + mpc.F4*Zref;
	mpc.g = mpc.gamma + mpc.gamma_x*x_bf(:,k+1) + mpc.gamma_u*u(:,k) + mpc.gama_w*Wpred;

    [z,fval,exitflag,iter,lambda] = qpOASES(mpc.H,mpc.f,mpc.Gamma,mpc.under_z,mpc.over_z,[],mpc.g);
    
    u(:,k+1) = z([1 2]);
end

% plot(t_sim,y_bo,'--')
% hold on
ax(1) = subplot(311);
stairs(t_sim,y_bf)

ax(2) = subplot(312);
stairs([t_sim t_sim(end)+1],u(1,:))
hold on
plot(1:(N_sim+1),mpc.u_max(1)*ones(1,N_sim+1))
plot(1:(N_sim+1),mpc.u_min(1)*ones(1,N_sim+1))

ax(3) = subplot(313);
stairs([t_sim t_sim(end)+1],u(2,:))
hold on
plot(1:(N_sim+1),mpc.u_max(2)*ones(1,N_sim+1))
plot(1:(N_sim+1),mpc.u_min(2)*ones(1,N_sim+1))

linkaxes(ax,'x')
