clear all

T_min = 70; T_max = 320;
P_min = 0.5; P_max = 20;

T_T_P = linspace(T_min, T_max, 100); % from T_min  to T_max
P_T_P = linspace((P_min), (P_max), 100); % from P_in   to P_max

for i=1:100
    for j=1:100
        H(i,j)   = CoolProp.PropsSI('H', 'T', T_T_P(i), 'P', 1e5*P_T_P(j), 'Nitrogen');
        S(i,j)   = CoolProp.PropsSI('S', 'T', T_T_P(i), 'P', 1e5*P_T_P(j), 'Nitrogen');
        rho(i,j) = CoolProp.PropsSI('D', 'T', T_T_P(i), 'P', 1e5*P_T_P(j), 'Nitrogen');
        u(i,j)   = CoolProp.PropsSI('U', 'T', T_T_P(i), 'P', 1e5*P_T_P(j), 'Nitrogen');
        Cp(i,j)  = CoolProp.PropsSI('C', 'T', T_T_P(i), 'P', 1e5*P_T_P(j), 'Nitrogen');
    end
end


H_min   = min(min(H));
S_min   = min(min(S));
rho_min = min(min(rho));
u_min   = min(min(u));

H_max   = max(max(H));
S_max   = max(max(S));
rho_max = max(max(rho));
u_max   = max(max(u));

P_P_H = linspace((P_min), (P_max), 100); % from P_in   to P_max
H_P_H = linspace(H_min, H_max, 100); % from H_min  to H_max

for i=1:100
    for j=1:100
        X_P_H(i,j)     = CoolProp.PropsSI('Q'  , 'P', 1e5*P_P_H(i), 'H', H_P_H(j), 'Nitrogen');
        T_P_H(i,j)     = CoolProp.PropsSI('T'  , 'P', 1e5*P_P_H(i), 'H', H_P_H(j), 'Nitrogen');
        rho_P_H (i,j)  = CoolProp.PropsSI('D'  , 'P', 1e5*P_P_H(i), 'H', H_P_H(j), 'Nitrogen');
        Z_P_H(i,j)     = CoolProp.PropsSI('Z'  , 'P', 1e5*P_P_H(i), 'H', H_P_H(j), 'Nitrogen');
        S_P_H(i,j)     = CoolProp.PropsSI('S'  , 'P', 1e5*P_P_H(i), 'H', H_P_H(j), 'Nitrogen');
        Cp_P_H(i,j)    = CoolProp.PropsSI('C'  , 'P', 1e5*P_P_H(i), 'H', H_P_H(j), 'Nitrogen');
        gamma_P_H(i,j) = 1.4013;
    end
end

u_u_rho   = linspace(u_min, u_max, 100); % from u_min   to u_max
rho_u_rho = logspace(log10(rho_min), log10(rho_max), 100); % from rho_min to rho_max

for i=1:100
    for j=1:100
        X_u_rho(i,j)   = min(max(CoolProp.PropsSI('Q'  , 'U', u_u_rho(i), 'D', rho_u_rho(j), 'Nitrogen'),-1),2);
        P_u_rho(i,j)   = max(CoolProp.PropsSI('P'  , 'U', u_u_rho(i), 'D', rho_u_rho(j), 'Nitrogen'),0);
        T_u_rho(i,j)   = max(CoolProp.PropsSI('T'  , 'U', u_u_rho(i), 'D', rho_u_rho(j), 'Nitrogen'),0);
        H_u_rho(i,j)   = max(CoolProp.PropsSI('H'  , 'U', u_u_rho(i), 'D', rho_u_rho(j), 'Nitrogen'),0);
    end
end

P_SV_P  = linspace((P_min), (P_max), 100); % from P_in   to P_max
for i=1:100
    HG_SV_P(i)  = CoolProp.PropsSI('H'  , 'P', 1e5*P_SV_P(i), 'Q', 1, 'Nitrogen'); % enthalpy
    T_SV_P(i)   = CoolProp.PropsSI('T'  , 'P', 1e5*P_SV_P(i), 'Q', 1, 'Nitrogen'); % temperature
end

% helium properties with SL and P inputs
P_SL_P  = linspace((P_min), (P_max), 100); % from P_in   to P_max

for i=1:100
    HL_SL_P(i)  = CoolProp.PropsSI('H'  , 'P', 1e5*P_SV_P(i), 'Q', 0, 'Nitrogen'); % enthalpy
end

% helium properties with P and X inputs
P_P_X  = linspace((P_min), (P_max), 100); % from P_in   to P_max
X_P_X  = linspace(0, 1, 100); % from 0 to 1

for i=1:100
    for j=1:100
        H_P_X(i,j) = CoolProp.PropsSI('H'  , 'P', P_P_X(i)*1e5, 'Q', X_P_X(j), 'Nitrogen');
    end
end

save n2p