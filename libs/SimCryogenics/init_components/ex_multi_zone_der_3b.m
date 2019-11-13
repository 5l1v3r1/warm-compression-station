function x_dot = ex_multi_zone_der_3b(in)

Th = in(1); Tm = in(2); Tc = in(3); % entrées
Mh = in(4); Mm = in(5); Mc = in(6);
Ph = in(7); Pm = in(8); Pc = in(9);

N = round(in(10)); % paramètres techno

Vh = in(11); Vm = in(12); Vc = in(13);% paramètres  physiques
Kh = in(14); Km = in(15); Kc = in(16);
hh_m = in(17);  hh_c = in(18);  hm_c = in(19);

sensh = in(20); sensm = in(21); sensc = in(22);

M = in(23);

gas1 = in(24); gas2 = in(25); gas3 = in(26);

H = in(27:27+(3*N)-1); % états

x_dot = ex_multizone_conti_centree_der_3b(Th,Tm,Tc,Mh,Mm,Mc,Ph,Pm,Pc,N,Vh,Vm,Vc,hh_m,hh_c,hm_c,sensh,sensm,sensc,M,gas1,gas2,gas3,H);

if isinf(sum(x_dot))==1 || isnan(sum(x_dot))==1
    x_dot = zeros(N*2,1);
end