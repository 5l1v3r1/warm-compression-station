function [ Cp ] = H_P_to_Cp( H, P, gas )

switch gas
    case 0
        Cp  = hecalc(14, 0, 'H', H ,'P', P*1e5, 0);
    case 1
        for i=1:length(H)
            Cp(i,1) = CoolProp.PropsSI('Cp', 'T', H(i), 'P', P*1e5, 'Nitrogen');
        end
end

