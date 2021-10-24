%Ham can xap xi
close all
clc
l1 = 0.3;
l2 = 0.5;
theta1 = -pi:0.001:pi;
theta2 = -pi:0.001:pi;
x =  l1*cos(theta1)+l2*cos(theta1 + theta2);
y =  l1*sin(theta1)+l2*sin(theta1 + theta2);
%Du lieu dung de huan luyen NN
K =300;
X = 2*pi*rand(2,K)-pi;
D=[l1*cos(X(1,:)) + l2*cos(X(1,:) + X(2,:));...
   l1*sin(X(1,:)) + l2*sin(X(1,:) + X(2,:))];
figure(1)
plot(D(1,:),D(2,:),'k*')
grid on;
% Khoi tao mang va huan luyen
N=12;
mynet=newff(X,D,N,{'tansig' 'purelin'});
mynet=train(mynet,X,D);
%Danh gia ket qua huan luyen
ynn=sim(mynet,X);
hold on;
plot(ynn(1,:), ynn(2,:),'ro')
xlabel('x');
ylabel('y');
grid on;
title({['Ket qua huan luyen voi'];[ 'N =',num2str(N)]});
legend('Tap du lieu huan luyen','Ket qua huan luyen');
%Nhap gia tri goc bat ky
figure(2);
theta  = [pi/2; pi/4];
%Tinh vi tri theo ham phi tuyen
pos_cal = [l1*cos(theta(1,:)) + l2*cos(theta(1,:) + theta(2,:));...
        l1*sin(theta(1,:)) + l2*sin(theta(1,:) + theta(2,:))];
%Tinh vi tri theo ham huan luyen
pos_nn = sim(mynet,theta);
plot(pos_cal(1,:), pos_cal(2,:),'ro')
hold on
plot(pos_nn(1,:), pos_nn(2,:),'k*')
xlabel('x');
ylabel('y');
grid on;
err = norm(pos_cal - pos_nn)
title({['Ket qua kiem tra voi N = ', num2str(N)];...
        ['theta1 =',num2str(theta(1,:)),',', 'theta2 =',num2str(theta(2,:))];
        ['sai so = ', num2str(err)]});
legend('Vi tri tinh toan','Vi tri huan luyen');
