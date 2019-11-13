function delta = lins_perso(A,B)
    delta = linsolve(A,B,struct('SYM',true,'POSDEF',true));
end