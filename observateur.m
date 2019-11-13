
sysd = c2d(CE.sys,Tp);

for i=1:length(sysd.OutputName) 
    SEL(i,1) = 1-(strcmp(sysd.OutputName{i}(1),'$')||strcmp(sysd.OutputName{i}(1),'P'));
end
SEL(5) = 1;

SEL_MAT = diag(SEL);
SEL_MAT = SEL_MAT(sum(SEL_MAT)==1,:);

SEL = logical(SEL);

A = sysd.a;
B = sysd.b;
C = sysd.c(SEL,:);
D = sysd.d(SEL,:);

Call = sysd.c();
Dall = sysd.d();

Bunc = B(:,[9 10]); Dunc = D(:,[9 10]);
Ao = [A Bunc; zeros(size(Bunc,2),size(A,1)), eye(size(Bunc,2))];
Bo = [B; zeros(size(Bunc,2),size(B,2))];
Co = [C Dunc];
Do = D;

Q = ones(length(Ao),1)./[abs(CE.pf.x_0); 1; 1];
Q(20) = 0;
R = ones(size(C,1),1).*CE.pf.out_0(SEL);
R(1) = 0.0001*R(1);
L = dlqr(Ao',Co',100*diag(Q),diag(R))';

Aoe = Ao-L*Co;
Boe = [Bo-L*Do L];
Coe = eye(length(Ao));
Doe = zeros(size(Coe*Boe));
Coes = [Call Dall(:,9:10)];
Does = [Dall];


