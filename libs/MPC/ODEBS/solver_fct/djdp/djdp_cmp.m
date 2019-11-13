function der = djdp_cmp(H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,z)
    

    na = size(Gamma,1);
    nh = size(H,2);
    
    ind = zeros(na,1);
    cstp = zeros(na,1);
    
    cst = -g;
    k = 0;
    
    for i=1:na
        for j=1:nh
            cst(i) = cst(i) + Gamma(i,j)*z(j);
        end
        if cst(i)>0
            k = k + 1;
            cstp(k,1) = 3*cst(i)^2*alpha(i);
            ind(k) = i;
        end
    end
    
    der = h;
    for i=1:nh
        for j=1:nh
        	der(i) = der(i) + H(i,j)*z(j);
        end
    end
    
    for i=1:nh
        for j=1:k
            der(i) = der(i) + Gamma(ind(j),i)'*cstp(j);
        end
        der(i) = der(i) + alpha_max(i).*max(z(i)-ub(i),0) - alpha_min(i).*max(lb(i)-z(i),0);
    end
    
    der = -der;
   
end