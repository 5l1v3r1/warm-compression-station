function [ Input ] = corr_ind( Input )
% This function corrects indices to execute the routine hecalc

    switch Input
        case 9 % enthalpy
            Input = 6; 
        case 8 % entropy
            Input = 5; 
        case 0 % quality
            Input = 9; 
        case 11 % energy
            Input = 7; 
    end

end

