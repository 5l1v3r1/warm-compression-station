function den = denom_cmp(H,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,dt,z)

    global lambda__
    
    na = size(Gamma,1);
    nh = size(H,2);
    
    ind = zeros(na,1);
    cstp = zeros(na,1);
    
    cst = -g;
    
    den = zeros(nh);
    k = 0;
    
    for i=1:na
        for j=1:nh
            cst(i) = cst(i) + Gamma(i,j)*z(j);
        end
        if cst(i)>0
            k = k + 1;
            cstp(k,1) = dt/2*lambda__*6*alpha(i).*cst(i);
            ind(k) = i;
        end
    end    
    
    a = dt*lambda__/2;
    hmm = a*(alpha_max.*max(z-ub,0) + alpha_min.*max(lb-z,0));
    
    for i=1:nh
        for l=1:i
            den(l,i) = a*H(i,l);
            for j=1:k
                den(l,i) = den(l,i) + Gamma(ind(j),l)*cstp(j)*Gamma(ind(j),i);
                den(i,l) = den(l,i);
            end
            
        end
        den(i,i) = den(i,i)  + hmm(i) + 1;
    end
    
end

