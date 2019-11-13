nz = 50;
H = (rand(nz)-0.5)^3; H = H*H'+10*eye(nz); chol(H);
eigenmax(H)