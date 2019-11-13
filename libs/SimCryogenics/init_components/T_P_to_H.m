function [ H ] = T_P_to_H( T, P, gas )

switch gas
    case 0
        H  = hecalc(9, 0, 'T', T ,'P', P*1e5, 0);
    case 1
        for i=1:length(T)
            H(i,1) = CoolProp.PropsSI('H', 'T', T(i), 'P', P*1e5, 'Nitrogen');
        end
end

