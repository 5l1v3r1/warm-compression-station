function p = lins_perso_cmp(A,B)
    
    nh = length(A); 
    C = zeros(nh);
    y = zeros(nh,1);
    p = zeros(nh,1);
    
    % cholesky
	for i=1:nh
        temp = 0;
		for k=1:i
            temp = temp - C(k,i)*C(k,i);
        end
        
		C(i,i) = sqrt(A(i,i) + temp);
		if (C(i,i) <= 0)
            error('error')
        end

		for j=i+1:nh
            temp = 0;
			for k=1:i
				temp = temp - C(k,i)*C(k,j);
            end
			C(i,j) = (A(i,j)+temp)/C(i,i);
        end
    end
    
    % up and down
	for i=1:nh
		temp = B(i);
		for k=1:i
			temp = temp - C(k,i)*y(k);
        end
		y(i) = temp/C(i,i);
    end

	for i=nh:-1:1
		temp = y(i);
		for j=nh:-1:1
			temp = temp - C(i,j)*p(j);
        end
		p(i) = temp/C(i,i);
    end
    
end