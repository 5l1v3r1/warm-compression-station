function [ Pr ] = H_P_to_Pr( H, P, gas )

switch gas
    case 0
        Pr  = hecalc(28, 0, 'T', H ,'P', P*1e5, 0);
    case 1
        for i=1:length(H)
            Pr(i,1) = CoolProp.PropsSI('H', 'T', H(i), 'P', P*1e5, 'Nitrogen');
        end
end

