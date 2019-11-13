
for i=1:9
    M1 = i/9/2;
    sim('aptim_refr')
    DHp(i) = DH(end,2);
end

hold all
M1p = (1:9)/9/2;
plot(M1p,-DHp)
