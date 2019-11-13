
clear all

Tin=50;
Pin=16;

gamma = hecalc(16,0,'T',Tin,'P',Pin*1e5,0);
rho = hecalc(3,0,'T',Tin,'P',Pin*1e5,0);
Z = hecalc(5,0,'T',Tin,'P',Pin*1e5,0);
R = 8.3144621;
Mhe = 4.0026*10^-3;

Pout = 1:0.1:17;
for i=1:length(Pout)
    rp_crit(i) = (2/(gamma+1))^(gamma/(gamma-1));
    rp(i) = min(Pout(i)/Pin,1);
    rp_c(i) = max(rp_crit(i),rp(i));

    Gsonic(i) = sqrt(Pin*rho*gamma*(2/(gamma+1))^((gamma+1)/(gamma-1)));
    Gsub(i) = sqrt(2*Pin*rho*gamma/(gamma-1)*(rp_c(i)^(2/gamma) - rp_c(i)^((gamma+1)/gamma)));
end

plot(1./rp,Gsonic,1./rp,Gsub)