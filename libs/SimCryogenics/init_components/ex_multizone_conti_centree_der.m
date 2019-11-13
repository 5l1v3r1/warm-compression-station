function x_p = ex_multizone_conti_centree_der(Th,Tc,Mh,Mc,Ph,Pc,N,Vh,Vc,h,M,gas1,gas2,x)

Th_out(1:N) = x(1:2:2*N); Tc_out(1:N) = x(2:2:2*N);

Vh = Vh./N; Vc = Vc./N;

Th_out  = [Th Th_out];   Tc_out = [Tc_out Tc];
Th_outp = (Th_out(1:end-1) + Th_out(2:end))/2;
Tc_outp = (Tc_out(1:end-1) + Tc_out(2:end))/2;

LMTD = Th_outp - Tc_outp;
%LMTD = (Th_out(1:N) - Tc_out(1:N) - Th_out(2:N+1) + Tc_out(2:N+1)) / log((Th_out(1:N) - Tc_out(1:N))/(Th_out(2:N+1) - Tc_out(2:N+1)));

switch gas1
    case 0 
        rhoh = hecalc(3,0,'T',Th_outp,'P',Ph*1e5,0)';
        Cph = hecalc(14,0,'T',Th_outp,'P',Ph*1e5,0)';
    case 1
        for i=1:length(Th_outp)
            rhoh = CoolProp.PropsSI('D', 'T', Th_outp(i), 'P', Ph*1e5, 'Nitrogen');
            Cph = CoolProp.PropsSI('C', 'T', Th_outp(i), 'P', Ph*1e5, 'Nitrogen');
        end
end

switch gas2
    case 0 
        rhoc = hecalc(3,0,'T',Tc_outp,'P',Pc*1e5,0)';
        Cpc = hecalc(14,0,'T',Tc_outp,'P',Pc*1e5,0)';
    case 1
        for i=1:length(Tc_outp)
            rhoc = CoolProp.PropsSI('D', 'T', Tc_outp(i), 'P', Pc*1e5, 'Nitrogen');
            Cpc = CoolProp.PropsSI('C', 'T', Tc_outp(i), 'P', Pc*1e5, 'Nitrogen');
        end
end

Cpalu = alcalc(mean([Th_outp;Tc_outp]));

Q = ( LMTD  ).*h./N;

convh = ((Mh'.*Cph').*(Th_out(1:end-1)-Th_out(2:end)));
convc = ((Mc'.*Cpc').*(Tc_out(2:end)-Tc_out(1:end-1)));

Th_out_p = (convh-Q)./(rhoh'.*Vh.*Cph'+Cpalu*M/N/2);
Tc_out_p = (convc+Q)./(rhoc'.*Vc.*Cpc'+Cpalu*M/N/2);

x_p(1:2:N*2,1) = Th_out_p; x_p(2:2:N*2,1) = Tc_out_p;



