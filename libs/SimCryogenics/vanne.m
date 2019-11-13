function M = vanne(PosR, Tin, Pin, Pout, CVmax, R, Xt)

CV = CVmax/R*(exp(PosR/100*log(R))-(1-PosR/100));

gamma = hecalc(16,0,2,Tin,1,Pin*1e5,1);
rho = hecalc(3,0,2,Tin,1,Pin*1e5,1);

Pr = (Pin-Pout)/Pin;
Pr_crit = gamma*Xt/1.4;

if (Pr<=Pr_crit),	% subsonic flow
	Xs = Pr;
	Y = 1 - Xs/(3*Pr_crit);
else				% sonic flow
	Xs = Pr_crit;
	Y = 2/3;
end

K = 2.4e-5;		% valve conversion factor
M = K*(1e5)^.5*CV*Y*sqrt(rho*Xs*Pin);

