classdef ode_based_solver < handle

    properties
        Gamma, g, H, h, lb, ub
        alpha_ind, alpha_min_ind, alpha_max_ind
        alpha, alpha_min, alpha_max
        
        p

        nz, nc
          
        ppl,    ppu
        Gpu,    Gpl,    G
        lambda1, lambda2
        num_pl, num_pu
        delta_ppl, delta_ppu
        Hpl, Hpu
        den
        LTE,    EEE,    r,    
        dt,     dt_new
        REDO
        delta
    
        lambda__ = 0.585786437626905
        a__ = 1.0
        b__ = 1.207106781186548
        c__ = 0.207106781186548
        d__ = 0.292893218813453
        e__ = -0.040440114519881
        f__ = 1.707106781186548
        g__ = 4.121320343559642
        l__ = 2.414213562373095
        
        REL_TOL
        ABS_TOL
    end
    
    methods
        
        function obj = ode_based_solver(H,Gamma,alpha_ind,...
                                    alpha_min_ind,alpha_max_ind)

            obj.H = H; 
            obj.Gamma = Gamma;
            obj.alpha_ind = alpha_ind;
            obj.alpha_min_ind = alpha_min_ind;
            obj.alpha_max_ind = alpha_max_ind;

            obj.nc = size(obj.Gamma,1);
            obj.nz = size(obj.H,1);
            
            ALPHA = max(eig(obj.H))*1e9;
            
            obj.alpha = ALPHA*ones(obj.nc,1);
            obj.alpha_min = ALPHA*ones(obj.nz,1);
            obj.alpha_max = ALPHA*ones(obj.nz,1);
            
            obj.REL_TOL = 1e3/max(eig(H));
            obj.ABS_TOL = 1000;
            
        end
        
         function maj(obj,h,g,lb,ub,alpha,alpha_min,alpha_max)
                obj.h = h;
                obj.g = g;
                obj.lb = lb;
                obj.ub = ub;
                obj.alpha(obj.alpha_ind) = alpha;
                obj.alpha_min(obj.alpha_min_ind) = alpha_min;
                obj.alpha_max(obj.alpha_max_ind) = alpha_max;
         end

        function num_pl_fct(obj)
            obj.num_pl = -(obj.ppl-obj.p) + obj.lambda__*obj.dt*(obj.Gpl+obj.G)/2;
        end
        
        function num_pu_fct(obj)
            obj.num_pu = -(obj.a__*obj.ppu-obj.b__*obj.ppl+obj.c__*obj.p) + obj.d__*obj.dt*obj.Gpu;
        end
        
        function saut_pl(obj)
            obj.ppl = obj.ppl + obj.delta_ppl;
        end 
        
        function saut_pu(obj)
            obj.ppu = obj.ppu + obj.delta_ppu;
        end

        function analyse(obj)
            obj.LTE = 2*obj.e__*obj.dt* ( obj.f__*obj.G - obj.g__*obj.Gpl + obj.l__*obj.Gpu );
			obj.EEE = obj.REL_TOL*abs(obj.Gpu)+obj.ABS_TOL;
            obj.r = norm(obj.LTE./obj.EEE)^.5;            

            if (obj.r<2 ) %&& norm(obj.Gpu)<10*norm(obj.G)
                obj.dt = max(min(obj.dt*obj.r^(-1/3),4*obj.dt),0.25*obj.dt);
                obj.p = obj.ppu;
                obj.G = obj.Gpu;
            else
                obj.dt = obj.dt/10;
            end
            
            
        end
    end

end

