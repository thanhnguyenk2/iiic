%Ham can xap xi
close all
x=-10:0.001:10;
y=0.1.*x.^(2)+ 2.*sin(x)+ log10(x.^2+1);
figure(1)
plot(x,y);
hold on;
title('y=0.1*x^(2)+ 2*sin(x)+ log10(x^2+1)');
grid on;

%Du lieu dung de huan luyen NN
K =300;
X = 20*rand(1,K)-10;
D=0.1.*X.^(2)+ 2*sin(X)+ log10(X.^2+1);
figure(2)
plot(X,D,'k.')
grid on;
title('Du lieu huan luyen');
%Khoi tao mang va huan luyen
N=12;
mynet=newff(X,D,N,{'tansig' 'purelin'});
mynet=train(mynet,X,D);

%Danh gia ket qua huan luyen
ynn=sim(mynet,x);

hold on;
plot(x,y,'b',x,ynn,'r')
grid on;
title({['Ket qua huan luyen voi'];[ 'N =',num2str(N)]});
legend('Tap du lieu huan luyen','Ham phi tuyen','Ket qua huan luyen');


