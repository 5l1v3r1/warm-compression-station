function den = denom(H,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,dt,z)

    global lambda__

    cst = Gamma*z-g;
    ind = cst>0;
%     cst = cst./(cst+1e-4);
%     cst = cst.^2;
%     cst = (cst./(cst+1e-3)).^2;
    cst = 6*cst;
    Hp = Gamma(ind,:)'*diag(alpha(ind).*cst(ind))*Gamma(ind,:);
    Hmm = diag(alpha_max.*max(z-ub,0) + alpha_min.*max(lb-z,0));
    den = eye(length(H)) + dt*lambda__*(H+Hp+Hmm)/2 ;
    
end

