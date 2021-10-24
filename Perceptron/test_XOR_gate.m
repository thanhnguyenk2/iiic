%w=[0.1;0.5;0.2];
x=[-1;0;0];
z1=my_perceptron(w1,x);
z2=my_perceptron(w2,x);
y=my_perceptron(w3,[-1;z1;z2])