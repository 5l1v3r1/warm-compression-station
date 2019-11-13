
close all
clc

load dis

for i=1:length(dis)
   dis2(i,dis(i,2)) = 1; 
end

A = zeros(4);
for i=1:size(dis,1)   
    for j=1:4
        for k=1:4
            try
                A(j,k) = A(j,k) + ((dis(i,2)==k) * ((dis(i+1,2)==j) + (dis(i-1,2)==j)));
            catch
                try
                    A(j,k) = A(j,k) + ((dis(i,2)==k) * (dis(i-1,2)==j));
                catch
                    A(j,k) = A(j,k) + ((dis(i,2)==k) * (dis(i+1,2)==j));
                end
            end
        end
    end
end
disp(A);