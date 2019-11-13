function mpc = csrt_val_maj_mpc(cstr_val,mpc)

    % récupération des nouvelles valeurs de contraintes 
    [nu, ~, ~, ~, nyc] = unpk_size_mpc(mpc.N);
    sel_in = cumsum([0 nyc nu nu nu nu]);
    cstr_y(:,1) = cstr_val(sel_in(1)+1:sel_in(2));
    du_max(:,1) = cstr_val(sel_in(2)+1:sel_in(3));
    du_min(:,1) = cstr_val(sel_in(3)+1:sel_in(4));
    u_max(:,1) = cstr_val(sel_in(4)+1:sel_in(5));
    u_min(:,1) = cstr_val(sel_in(5)+1:sel_in(6));
    
    % partie avec n_iv élements (instant de vérification)
    gamma_y = zeros(mpc.N.n_iv*mpc.N.nyc,1);
    for i=1:mpc.N.n_iv
        gamma_y(((i-1)*mpc.N.nyc+1):(i*mpc.N.nyc),1) = cstr_y;
    end
    
    % partie avec n_id élements (intants de décisions)
    if strcmp(mpc.solver,'ode-based')
        over_z_unit = [u_max];
        under_z_unit = [u_min];
    elseif strcmp(mpc.solver,'active-set')
        over_z_unit = [u_max; 1e9*ones(mpc.N.n_soft,1)];
        under_z_unit = [u_min; -1e9*ones(mpc.N.n_soft,1)];
    end
    
    du_min_max = [du_max; -du_min];

    id = [0 mpc.i.id];
    gamma_d = zeros(mpc.N.n_id*mpc.N.nu*2,1);
    over_z = zeros(mpc.N.n_id*mpc.N.n_uv,1);
    under_z = zeros(mpc.N.n_id*mpc.N.n_uv,1);
    
    for i=1:mpc.N.n_id
        gamma_d(((i-1)*mpc.N.nu*2+1):(i*mpc.N.nu*2),1) = du_min_max*(id(i+1)-id(i));
        
        ind = (i-1)*(mpc.N.n_uv)+1:i*(mpc.N.n_uv);
        over_z(ind,1) = over_z_unit;
        under_z(ind,1) = under_z_unit;
    end
    
    mpc.pb.gamma_cst = [mpc.pb.gamma_cst(1:length(gamma_y)); gamma_d]; %changer!
    mpc.pb.over_z = over_z;
    mpc.pb.under_z = under_z;
end