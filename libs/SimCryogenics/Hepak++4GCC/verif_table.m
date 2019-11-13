
log_sel_rho = 1
log_sel_u = 1

T_max = 320;
T_min = 4;
P_min = 1;
P_max = 20;

rho = hecalc(3,0,'T',linspace(T_min,T_max,100),'P',linspace(P_min,P_max,100)'*1e5,0);
rho_min = min(min(rho));
rho_max= max(max(rho));

u = hecalc(11,0,'T',linspace(T_min,T_max,100),'P',linspace(P_min,P_max,100)'*1e5,0);
u_min = min(min(u));
u_max= max(max(u));

if log_sel_rho==1
	rho = logspace(log10(rho_min),log10(rho_max),101);
else
	rho = linspace((rho_min),(rho_max),101);
end

if log_sel_u==1
	u = logspace(log10(u_min),log10(u_max),200);
else
	u = linspace((u_min),(u_max),200);
end

x = hecalc(0,0,11,u,3,rho',0);

h = surf(rho,u,x')
% set(get(h,'Parent'),'XScale','log');
% set(get(h,'Parent'),'YScale','log');

ylim([0.1e5,0.3e5])
xlim([10 25])

rho_5 = hecalc(3,0,0,0.95,'P',1e5,0)
u_5 = hecalc(11,0,0,0.95,'P',1e5,0)