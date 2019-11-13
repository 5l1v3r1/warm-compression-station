function x_p = ex_multizone_conti_centree_der_4b(Hh,Hm,Hc,Hvc,Mh,Mm,Mc,Mvc,Ph,Pm,Pc,Pvc,N,Vh,Vm,Vc,Vvc,hh_m,hh_c,hh_vc,hm_c,hm_vc,hc_vc,sensh,sensm,sensc,sensvc,M,H)

Hh_out(1:N) = H(1:4:4*N); Hm_out(1:N) = H(2:4:4*N); Hc_out(1:N) = H(3:4:4*N); Hvc_out(1:N) = H(4:4:4*N); 

Vh = Vh./N; Vm = Vm./N; Vc = Vc./N;  Vvc = Vvc./N;
                                                         
if sensh == 0, Hh_out  = [Hh Hh_out]; else Hh_out  = [Hh_out Hh]; end
if sensm == 0, Hm_out  = [Hm Hm_out]; else Hm_out  = [Hm_out Hm]; end
if sensc == 0, Hc_out  = [Hc Hc_out]; else Hc_out  = [Hc_out Hc]; end 
if sensvc == 0, Hvc_out  = [Hvc Hvc_out]; else Hvc_out  = [Hvc_out Hvc]; end 
    
Th_outp = (hecalc(2,0,9,Hh_out(1:end-1),'P',Ph*1e5,0) + hecalc(2,0,9,Hh_out(2:end),'P',Ph*1e5,0))/2;
Tm_outp = (hecalc(2,0,9,Hm_out(1:end-1),'P',Pm*1e5,0) + hecalc(2,0,9,Hm_out(2:end),'P',Pm*1e5,0))/2;
Tc_outp = (hecalc(2,0,9,Hc_out(1:end-1),'P',Pc*1e5,0) + hecalc(2,0,9,Hc_out(2:end),'P',Pc*1e5,0))/2;
Tvc_outp = (hecalc(2,0,9,Hvc_out(1:end-1),'P',Pvc*1e5,0) + hecalc(2,0,9,Hvc_out(2:end),'P',Pvc*1e5,0))/2;

Dt1 = Th_outp - Tm_outp;
Dt2 = Th_outp - Tc_outp;
Dt3 = Th_outp - Tvc_outp;
Dt4 = Tm_outp - Tc_outp;
Dt5 = Tm_outp - Tvc_outp;
Dt6 = Tc_outp - Tvc_outp;

rhoh = hecalc(3,0,'T',Th_outp,'P',Ph*1e5,0)';
Cph = hecalc(14,0,'T',Th_outp,'P',Ph*1e5,0)';

rhom = hecalc(3,0,'T',Tm_outp,'P',Pm*1e5,0)';
Cpm = hecalc(14,0,'T',Tm_outp,'P',Pm*1e5,0)';

rhoc = hecalc(3,0,'T',Tc_outp,'P',Pc*1e5,0)';
Cpc = hecalc(14,0,'T',Tc_outp,'P',Pc*1e5,0)';

rhovc = hecalc(3,0,'T',Tvc_outp,'P',Pvc*1e5,0)';
Cpvc = hecalc(14,0,'T',Tvc_outp,'P',Pvc*1e5,0)';

Cpalu = alcalc(mean([Th_outp;Tm_outp;Tc_outp;Tvc_outp]));

Q1 = ( Dt1  )*hh_m/N;
Q2 = ( Dt2  )*hh_c/N;
Q3 = ( Dt3  )*hh_vc/N;
Q4 = ( Dt4  )*hm_c/N;
Q5 = ( Dt5  )*hm_vc/N;
Q6 = ( Dt6  )*hc_vc/N;

convh = ((Mh').*((-1)^(sensh)).*(Hh_out(1:end-1)-Hh_out(2:end)));
convm = ((Mm').*((-1)^(sensm)).*(Hm_out(1:end-1)-Hm_out(2:end)));
convc = ((Mc').*((-1)^(sensc)).*(Hc_out(1:end-1)-Hc_out(2:end)));
convvc = ((Mvc').*((-1)^(sensvc)).*(Hvc_out(1:end-1)-Hvc_out(2:end)));

Hh_out_p = (convh-Q1-Q2-Q3)./(rhoh'.*Vh+Cpalu*M/N/2/Cph');
Hm_out_p = (convm+Q1-Q4-Q5)./(rhom'.*Vm+Cpalu*M/N/2/Cpm');
Hc_out_p = (convc+Q2+Q4-Q6)./(rhoc'.*Vc+Cpalu*M/N/2/Cpc');
Hvc_out_p = (convvc+Q3+Q5+Q6)./(rhovc'.*Vvc+Cpalu*M/N/2/Cpvc');

x_p(1:4:N*4,1) = Hh_out_p;  
x_p(2:4:N*4,1) = Hm_out_p; 
x_p(3:4:N*4,1) = Hc_out_p;
x_p(4:4:N*4,1) = Hvc_out_p;

