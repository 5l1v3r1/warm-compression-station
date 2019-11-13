function [ der ] = djdp(H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,z)

    cst = Gamma*z-g;
    ind =  cst>0;
%     cst = cst-1e-4*log(1e4*cst+1);
%     cst = cst-1e-6./(cst+1e-3) - 2*1e-3*log(cst+1e-3)-0.012815510558;
%     cst = cst - 1e-4*(log(cst+1e-4)-log(1e-4));
    cst = 3*cst.^2; 
    der = -( H*z+h+Gamma(ind,:)'*(alpha(ind).*cst(ind)) + ...
            alpha_max.*max(z-ub,0) - alpha_min.*max(lb-z,0) );
    
end

