
%Du lieu huan luyen mang NN
X = [e';de'];
D = theta';

%Huan luyen mang NN
N = 10; %so neuron o lop an
mynet = newff(X,D,N,{'logsig' 'purelin'});
mynet = train(mynet,X,D);

gensim(mynet)
