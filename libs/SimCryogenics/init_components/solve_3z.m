function [HHout, HMout, HCout] = solve_3z(Th0v ,Tm0v, Tc0v, Mh0v, Mm0v, Mc0v, Ph0v, Pm0v, Pc0v, Nv, Vhv, Vmv, Vcv, hh_mv, hh_cv, hm_cv, senshv, sensmv, senscv, Mv)

    f = @(Tt)ex_multizone_conti_centree_der_3b(	Th0v ,Tm0v, Tc0v, Mh0v, Mm0v, Mc0v, Ph0v, Pm0v, Pc0v,...
                        Nv, Vhv, Vmv, Vcv, hh_mv, hh_cv, hm_cv, senshv, sensmv, senscv, Mv, Tt);
                                        
                                        
    T(1:3:3*Nv,1) = linspace(Th0v  , Tc0v+0.5, Nv)'; % init guess Th
    T(2:3:3*Nv,1) = linspace(Th0v  , Tm0v,     Nv)'; % init guess Tm
    T(3:3:3*Nv,1) = linspace(Th0v-1, Tc0v,     Nv)'; % init guess Tc  

    opt = optimset('Display','off','TolFun',1e-10,'TolX',1e-10);
    T   = fsolve(f,T);
    
    HHout = [hecalc(9, 0, 'T', T(1:3:end),    'P', Ph0v , 0); zeros(10-Nv,1)];
    HMout = [hecalc(9, 0, 'T', T(end-1:-3:1), 'P', Pm0v , 0); zeros(10-Nv,1)];
    HCout = [hecalc(9, 0, 'T', T(end:-3:1),   'P', Pc0v , 0); zeros(10-Nv,1)];