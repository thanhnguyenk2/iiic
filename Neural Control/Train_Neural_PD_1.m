
%Du lieu huan luyen mang NN
K=length(e)
X = [e(2:K)';e(1:K-1)'];
D = theta(2:K)';

%Huan luyen mang NN
N = 15; %so neuron o lop an
mynet = newff(X,D,N,{'logsig' 'purelin'});
mynet = train(mynet,X,D);

gensim(mynet)
