clear all

TT = [3 100];
PP = [0.8 20];

Hmm = hecalc(9,0,'T',TT','P',PP*1e5,0);
HH = [min(min(Hmm)) max(max(Hmm))];



umm = hecalc(11,0,'T',TT','P',PP*1e5,0);
uu = [min(min(umm)) max(max(umm))];

rhomm = hecalc(3,0,'T',TT','P',PP*1e5,0);
rrho = [min(min(rhomm)) max(max(rhomm))];

u = linspace((uu(1)),(2.8e4),200);
rho = linspace((0.3),(rrho(2)),200);

figure(2)
x = hecalc(0,0,11,u',3,rho,0);
surf(rho,u,x)
ylim([20 2.8e4])
xlim([1 120])
u2 = linspace((uu(1)),(2.8e4),300);
rho2 = linspace((0.3),(rrho(2)),300);
xx = interp2(rho,u,min(max(x,-0.1),1.1),rho2',u2,'spline');


figure(1)
T = hecalc(2,0,11,u',3,rho,0);
surf(rho,u,T)
ylim([20 2.8e4])
xlim([1 150])

figure(1)
P = hecalc(1,0,11,u',3,rho,0)/1e5;
surf(rho,u,P)
ylim([20 2.8e4])
xlim([1 150])
zlim([0.5 3])

figure(2)
x = hecalc(0,0,9,H',3,rho,0);
surf(rho,u,x)
ylim([20 2.2e4])
xlim([1 150])

H = logspace(log10(HH(1)),log10(HH(2)),1100);
rho = logspace(log10(rho(1)),log10(rho(2)),1000);

figure(2)
x = hecalc(0,0,9,H','P',P*1e5,0);
surf(P,H,x)
ylim([5e3 3.5e4])
xlim([0.01 0.1])

sum((H<3.5e4)==1)
sum(((P>0.5) + (P<2.4))==2)