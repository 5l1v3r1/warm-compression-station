function [A,v] = aide_turbine2 (M,Tin,Pin,Pout,D,N,eta)

    gamma = hecalc(16,0,'T',Tin,'P',Pin*1e5,0);
    Z = hecalc(5,0,'T',Tin,'P',Pin*1e5,0);
    R = 8.3144621;
    Mhe = 4.0026*10^-3;
    
    rp_crit = (2/(gamma+1))^(gamma/(gamma-1));
    rp = Pout/Pin;
    rp_c = max(rp_crit,rp);

    C = sqrt(2*gamma/(gamma-1)*(rp_c^(2/gamma) - rp_c^((gamma+1)/gamma)));
        
    % M = C*Pin*1e5*A/sqrt(Z*R*Tin/Mhe);
    A=M*sqrt(Z*R*Tin/Mhe)/(C*Pin*1e5);
    Hin = hecalc(9,0,'T',Tin,'P',Pin*1e5,0);
    Sin = hecalc(8,0,'T',Tin,'P',Pin*1e5,0);
    HoutIs = hecalc(9,0,8,Sin,'P',Pout*1e5,0);
    
    Tout = hecalc(2,0,9,Hin*(1-eta)+eta*HoutIs,'P',Pout*1e5,0);
    disp(Tout);
    
    u1 = pi*N*D;
    c1 = sqrt(2*(Hin-HoutIs));
    v = u1/c1;