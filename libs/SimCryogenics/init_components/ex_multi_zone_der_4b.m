function x_dot = ex_multi_zone_der_4b(in)

Th = in(1); Tm = in(2); Tc = in(3); Tvc = in(4);%entrées
Mh = in(5); Mm = in(6); Mc = in(7); Mvc = in(8);
Ph = in(9); Pm = in(10); Pc = in(11); Pvc = in(12);

N = round(in(13)); % paramètres techno

Vh = in(14); Vm = in(15); Vc = in(16); Vvc = in(17);% paramètres  physiques
Kh = in(18); Km = in(19); Kc = in(20); Kvc = in(21);
hh_m = in(22);  hh_c = in(23);  hh_vc = in(24);
hm_c = in(25);  hm_vc = in(26);  hc_vc = in(27);
sensh = in(28); sensm = in(29); sensc = in(30); sensvc = in(31);


M = in(32);

T = in(33:33+(4*N)-1); % états

x_dot = ex_multizone_conti_centree_der_4b(Th,Tm,Tc,Tvc,Mh,Mm,Mc,Mvc,Ph,Pm,Pc,Pvc,N,Vh,Vm,Vc,Vvc,hh_m,hh_c,hh_vc,hm_c,hm_vc,hc_vc,sensh,sensm,sensc,sensvc,M,T);


 if isinf(sum(x_dot))==1 || isnan(sum(x_dot))==1
    x_dot = zeros(N*2,1);
end