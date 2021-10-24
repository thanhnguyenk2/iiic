X = [-1 -1 -1 -1 -1 -1;...
      3  1 -2  3 0 -1;...
      2 -2 0 1 -1 2];
X3 = [-1 -1 -1 ;...
      1  0  0 ;...
      0 1 0 ];
D1 = [1 0 0 0 0 0];
D2 = [0 1 1 0 0 0];
D3 = [1 1 0];
w1 = train_perceptron(X,D1)
w2 = train_perceptron(X,D2)
w3 = train_perceptron(X3,D3)
X_test = [-1 3 5]';
x1 = my_perceptron(w1,X_test);
x2 = my_perceptron(w2,X_test);
my_perceptron(w3,[-1 x1 x2]')