function [ouv] = m_f_dp_valve(M, Tin, Pin, Pout, CVmax, R, Xt)
% This function calculates the valve openning given the other boundary
% conditions. Precisely, this function takes the flowrate M that the valve 
% must generatate, and give the coresponding valve openning ouv.
% 
% Syntax:
% ouv = m_f_dp_valve(M, Tin, Pin, Pout, CVmax, R, Xt) 
%

f = @(PosR)(vanne(PosR, Tin, Pin, Pout, CVmax, R, Xt)-M);
opt = optimset('tolx',1e-12,'tolfun',1e-12);
ouv = fsolve(f,50,opt);

if ouv > 100
    error('ouv>100 : this valve is not capable to generate this flowrate with the given boundary conditions')
end 