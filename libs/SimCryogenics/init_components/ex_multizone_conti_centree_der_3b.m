function x_p = ex_multizone_conti_centree_der_3b(Hh,Hm,Hc,Mh,Mm,Mc,Ph,Pm,Pc,N,Vh,Vm,Vc,hh_m,hh_c,hm_c,sensh,sensm,sensc,M,gas1,gas2,gas3,H)

Hh_out(1:N,1) = H(1:3:3*N); Hm_out(1:N,1) = H(2:3:3*N); Hc_out(1:N,1) = H(3:3:3*N); 

Vh = Vh./N; Vm = Vm./N; Vc = Vc./N;
                                                         
if sensh == 0, Hh_out  = [Hh; Hh_out]; else Hh_out  = [Hh_out; Hh]; end
if sensm == 0, Hm_out  = [Hm; Hm_out]; else Hm_out  = [Hm_out; Hm]; end
if sensc == 0, Hc_out  = [Hc; Hc_out]; else Hc_out  = [Hc_out; Hc]; end 

switch gas1
    case 0
        Th_outp = (hecalc(2,0,9,Hh_out(1:end-1),'P',Ph*1e5,0) + hecalc(2,0,9,Hh_out(2:end),'P',Ph*1e5,0))/2;
        rhoh = hecalc(3,0,'T',Th_outp,'P',Ph*1e5,0);
        Cph = hecalc(14,0,'T',Th_outp,'P',Ph*1e5,0);
    case 1
        for i=1:length(Hh_out)-1
            Th_outp(i,1) = (CoolProp.PropsSI('T', 'H', Hh_out(i), 'P', Ph*1e5, 'Nitrogen')+CoolProp.PropsSI('T', 'H', Hh_out(i+1), 'P', Ph*1e5, 'Nitrogen'))/2;
            rhoh(i,1) = CoolProp.PropsSI('D', 'T', Th_outp(i), 'P', Ph*1e5, 'Nitrogen');
            Cph(i,1) = CoolProp.PropsSI('C', 'T', Th_outp(i), 'P', Ph*1e5, 'Nitrogen');
        end
end

switch gas2
    case 0 
        Tm_outp = (hecalc(2,0,9,Hm_out(1:end-1),'P',Pm*1e5,0) + hecalc(2,0,9,Hm_out(2:end),'P',Pm*1e5,0))/2;
        rhom = hecalc(3,0,'T',Tm_outp,'P',Pm*1e5,0);
        Cpm = hecalc(14,0,'T',Tm_outp,'P',Pm*1e5,0);
    case 1
        for i=1:length(Hh_out)-1
            Tm_outp(i,1) = (CoolProp.PropsSI('T', 'H', Hm_out(i), 'P', Pm*1e5, 'Nitrogen')+CoolProp.PropsSI('T', 'H', Hm_out(i+1), 'P', Pm*1e5, 'Nitrogen'))/2;
            rhom(i,1) = CoolProp.PropsSI('D', 'T', Th_outp(i), 'P', Pm*1e5, 'Nitrogen');
            Cpm(i,1) = CoolProp.PropsSI('C', 'T', Th_outp(i), 'P', Pm*1e5, 'Nitrogen');
        end
end

switch gas3
    case 0 
        Tc_outp = (hecalc(2,0,9,Hc_out(1:end-1),'P',Pc*1e5,0) + hecalc(2,0,9,Hc_out(2:end),'P',Pc*1e5,0))/2;
        rhoc = hecalc(3,0,'T',Tc_outp,'P',Pc*1e5,0);
        Cpc = hecalc(14,0,'T',Tc_outp,'P',Pc*1e5,0);
    case 1
        for i=1:length(Hh_out)-1
            Tc_outp(i,1) = (CoolProp.PropsSI('T', 'H', Hc_out(i), 'P', Pc*1e5, 'Nitrogen')+CoolProp.PropsSI('T', 'H', Hc_out(i+1), 'P', Pc*1e5, 'Nitrogen'))/2;
            rhoc(i,1) = CoolProp.PropsSI('D', 'T', Tc_outp(i), 'P', Pc*1e5, 'Nitrogen');
            Cpc(i,1) = CoolProp.PropsSI('C', 'T', Tc_outp(i), 'P', Pc*1e5, 'Nitrogen');
        end
end

Dt1 = Th_outp - Tm_outp;
Dt2 = Th_outp - Tc_outp;
Dt3 = Tm_outp - Tc_outp;

Cpalu = alcalc(mean([Th_outp Tm_outp Tc_outp]'))';

Q1 = ( Dt1  )*hh_m/N;
Q2 = ( Dt2  )*hh_c/N;
Q3 = ( Dt3  )*hm_c/N;

convh = ((Mh').*((-1)^(sensh)).*(Hh_out(1:end-1)-Hh_out(2:end)));
convm = ((Mm').*((-1)^(sensm)).*(Hm_out(1:end-1)-Hm_out(2:end)));
convc = ((Mc').*((-1)^(sensc)).*(Hc_out(1:end-1)-Hc_out(2:end)));

Hh_out_p = (convh-Q1-Q2)./(rhoh.*Vh+Cpalu*M/N/2./Cph);
Hm_out_p = (convm+Q1-Q3)./(rhom.*Vm+Cpalu*M/N/2./Cpm);
Hc_out_p = (convc+Q2+Q3)./(rhoc.*Vc+Cpalu*M/N/2./Cpc);

x_p(1:3:N*3,1) = Hh_out_p;  
x_p(2:3:N*3,1) = Hm_out_p; 
x_p(3:3:N*3,1) = Hc_out_p;