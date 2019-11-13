function x_dot = ex_multi_zone_der(in)

Th = in(1); Tc = in(2); % entrées
Mh = in(3); Mc = in(4); 
Ph = in(5); Pc = in(6); 

N = round(in(7)); % paramètres techno

Vh = in(8); Vc = in(9); % paramètres  physiques
Kh = in(10); Kc = in(11);
h = in(12);
M = in(13);
gas1 = in(14);
gas2 = in(15);

x = in(16:16+(2*round(N))-1); % états

x_dot = ex_multizone_conti_centree_der(Th,Tc,Mh,Mc,Ph,Pc,N,Vh,Vc,h,M,gas1,gas2,x);

if isinf(sum(x_dot))==1 || isnan(sum(x_dot))==1
    x_dot = zeros(N*2,1);
end