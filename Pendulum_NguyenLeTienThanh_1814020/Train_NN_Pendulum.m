load PendulumData01
K= length(u);
ResampleStep =10;
ue= u(1:ResampleStep:K);
ye= y(1:ResampleStep:K);
% Tap mau du lieu de huan luyen mang NN
Ke= length(ue);
X = [ue(2:Ke-1)';...
     ue(1:Ke-2)';... 
     ye(2:Ke-1)';...
     ye(1:Ke-2)'];
D = [ye(3:Ke)'];

% Khai bao mang NN va huan luyen
N = 25;
mynet = newff(X,D,N,{'logsig' 'purelin'});
mynet = train(mynet,X,D);

% Danh gia  
load PendulumData02
K= length(u);
uv= u(1:ResampleStep:K);
yv= y(1:ResampleStep:K);
ynn= zeros(size(yv));
Kv = length(uv);

for k = 3:Kv
    X= [uv(k-1);uv(k-2);ynn(k-1);ynn(k-2)];
    ynn(k)= sim(mynet,X);
end
plot(yv,'r');
hold on
plot(ynn,'b');
hold off