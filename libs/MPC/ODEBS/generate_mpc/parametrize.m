function [Pi_z, sel] = parametrize(n_d,N_p,id_i)

% This function generates the Pi_z paramterisation matrix and the
% associated apartenance vectors contained in the sel cell.
%
% usage : [Pi_z, sel] = param(n_d,N_p,id)
% where n_d is the number of control effort, N_p the preidction horizon
% and id the vector of optimisation instants.
% ex: [Pi_z, sel] = param(2,16,[1 2 4 8 16])
%
% usage : [Pi_z, sel] = param(n_d,N_p,id)
% where n_d is the number of desicion instant, N_p the preidction horizon
% and id represents cells wich contain vectors of optimisation instants 
% (one for each control effort).
% ex: [Pi_z, sel] = param(2,16,{[1 2 4 8 16],[1 8 16]})
%
% copy-paste the following code to have a precise idea of what is hapening
%
% Np = 16; % your hozizon prediction is 16
% nu = 3; % your have 3 control effort
% id1 = [1 2 4 8 12]; % the first control effort is parametrized like this
% id2 = [1 8];  % the second control effort is parametrized like this 
% id3 = [1 2 4 8];  % the third control effort is parametrized like this 
% id = {id1,id2,id3};
% 
% z = [1 1.5 0.5 2 1.5 3 2.5 4 2.5 3.5 5]'; 
% % and supose that the result of the optimisation problem is z
% 
% figure(1)
% [Pi_z sel] = parametrize(nu,Np,id);
% p = Pi_z*z;
% subplot(311)
% plot(1:Np,p(1:nu:end),'+-',id1,z(sel{1}),'ro')
% legend('interpolation','decision','Location','best')
% grid on
% subplot(312)
% plot(1:Np,p(2:nu:end),'+-',id2,z(sel{2}),'ro')
% legend('interpolation','decision','Location','best')
% grid on
% subplot(313)
% plot(1:Np,p(3:nu:end),'+-',id3,z(sel{3}),'ro')
% legend('interpolation','decision','Location','best')
% grid on

if iscell(id_i)
    assert(length(id_i)==n_d,'multi parametrized MPC : the number of control effort n_d must be equal to the number of array contained in the id cell');
    id = id_i;
else
    for k=1:n_d
        id{k} = id_i;
    end
end

n_z = 0;
id_full = [];
orig = [];
tempo = [];

for k=1:n_d
    n_z = n_z + length(id{k});
    id_full = [id_full id{k}];
    orig = [orig k*ones(1,length(id{k}))];
    tempo = [tempo 1:length(id{k})];
end

[~, b] = sort(id_full);
c = orig(b);
d = tempo(b);

S = 1:n_z;
for k=1:n_d
    n_id(k) = length(id{k});
    Pi_zk{k} = param_one(N_p,n_id(k),id{k});
    sel{k} = S(k==c);
end
Pi_z = zeros(N_p*n_d,n_z);
for i=1:n_z
    Pi_z(c(i):n_d:end,i) = Pi_zk{c(i)}(:,d(i));
end
    
function [ Pi_z ] = param_one( N_p, n_id, id )

Pi_z = zeros(N_p,n_id);

for i = 1:N_p
    for j = 1:n_id

        if id(j)==i
            Pi_z(i,j) = 1;
        end

        if j<length(id) && id(j+1)>i && id(j)<i
            Pi_z(i,j)  = 1*(id(j+1)  - i) / (id(j+1)-id(j)) ;
        end   

        if j>1 && id(j)>i && id(j-1)<i
            Pi_z(i,j)  = 1*(i-id(j-1)) / (id(j)-id(j-1)) ;
        end

        if j==n_id && i>id(end)
            Pi_z(i,j)  = 1;
        end

    end
end





