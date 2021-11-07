close all
clear
clc
load('data_speed.mat');
%Du lieu huan luyen mang NN
K = length(out.u); %so mau du lieu
X = [out.e(2:K)'; out.de(2:K)'; out.u(1:K-1)'];
D = out.u(2:K)';
%Ve du lieu huan luyen
subplot(3,1,1);
plot(out.e)
title('e');
subplot(3,1,2); 
plot(out.de)
title('de');
subplot(3,1,3); 
plot(out.u)
% title('u');
%Khoi tao mang NN va huan luyen
N = 15; % so no ron o lop an
mynet = newff(X,D,N,{'tansig' 'purelin'});
mynet = train(mynet,X,D);

gensim(mynet); %tao khoi Simulink thuc hien NN vua huan luyen


