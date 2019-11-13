clear variables
close all
clc

Tin = 300;
CVmax = 2.5;
R = 10;
Xt = 0.72;

% nominal
HP = 16; BP = 1.05; 
MP = 6:0.1:12;

for i=1:length(MP)
    M952(i) = vanne(100, Tin, MP(i), BP, CVmax, R, Xt);
    M953(i) = vanne(100, Tin, HP, MP(i), CVmax, R, Xt);
end

plot(MP,M952,MP,M953)
legend('apport','retrait')

clear M952
MP = 12;
ouv952=0:90;
for i=1:length(ouv952)
    M952(i) = vanne(ouv952(i), Tin, MP, BP, CVmax, R, Xt);
    ouv953(i) = m_f_dp_valve(M952(i), Tin, HP, MP, CVmax, R, Xt);
end
plot(ouv953,ouv952)

