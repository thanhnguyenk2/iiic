close all
clc
%Du lieu huan luyen mang NN
clc
clear
close all
load('data_ball_bean.mat');
K = length(out.u); %so mau du lieu
X = [out.e(1:K)'; out.de(1:K)'];
D = out.u(1:K)';
%Ve du lieu huan luyen
% subplot(3,1,1);
% plot(out.e)
% title('e');
% subplot(3,1,2); 
% plot(out.de)
% title('de');
% subplot(3,1,3); 
% plot(out.u)
% title('u');
%Khoi tao mang NN va huan luyen
N = 8; % so no ron o lop an
mynet = newff(X,D,N,{'tansig' 'purelin'});
mynet = train(mynet,X,D);

gensim(mynet); %tao khoi Simulink thuc hien NN vua huan luyen


