function [ mu ] = H_P_to_mu( H, P, gas )

switch gas
    case 0
        mu  = hecalc(25, 0, 'T', H ,'P', P*1e5, 0);
    case 1
        for i=1:length(H)
            mu(i,1) = CoolProp.PropsSI('H', 'T', H(i), 'P', P*1e5, 'Nitrogen');
        end
end

