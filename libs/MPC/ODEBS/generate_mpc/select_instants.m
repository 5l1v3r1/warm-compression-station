function Pi_1 = select_instants(Np,Nc,P)

Nd = numel(P);
for i=1:Nd
    for j=1:Np
        Pi_1((i-1)*Nc+1:i*Nc,(j-1)*Nc+1:j*Nc) = eye(Nc)*P(i)==j;
    end
end
