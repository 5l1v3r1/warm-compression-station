function [u, w, x, y_ref, manu, manu_val, cstr_val, cstr_rho, z] = recup_in_mpc(in, N)
    
    % recupération des différentes tailles
    [nu, nd, ns, nyt, nyc] = unpk_size_mpc(N);
    sel_in = cumsum([0 nu nd ns nyt nu nu nyc+4*nu nyc+4*nu]);

    u =      	in(sel_in(1)+1:sel_in(2)); % u(k-1) entrée à l'instant précédent 
    w =      	in(sel_in(2)+1:sel_in(3)); % w(k)
    x =      	in(sel_in(3)+1:sel_in(4)); % x(k)
    y_ref =   	in(sel_in(4)+1:sel_in(5)); % y_ref(k+i) 
    manu =    	in(sel_in(5)+1:sel_in(6)); % auto / manu auto=1, manu=0
    manu_val =  in(sel_in(6)+1:sel_in(7)); % valeur si manu
    cstr_val =  in(sel_in(7)+1:sel_in(8)); % valeurs des contraintes
    cstr_rho =	in(sel_in(8)+1:sel_in(9)); % poids associés
    z        =  in(sel_in(9)+1:end);

end