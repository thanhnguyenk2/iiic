X = [-1 -1 -1 -1 -1 -1 -1 ;...
     2 0 0 0 1 0 -1;...
     0 2 0 1 0 -1 0];
  
X4 = [-1 -1 -1 -1;...
      0 1 1 0 ;...
      0 0 0 0];
D1 = [1 0 0 0 1 1 0];
D2 = [0 0 0 0 0 1 1];
D3 = [1 1 0 0 0 0 0];
D4 = [1 0 0 0];
D5 = [0 1 1 1];
w1 = train_perceptron(X,D1)
w2 = train_perceptron(X,D2)
w3 = train_perceptron(X,D3)
w4 = train_perceptron(X4,D4)
w5 = train_perceptron(X4,D5)
X_test = [-1 2 0]';
x1 = my_perceptron(w1,X_test);
x2 = my_perceptron(w2,X_test);
x3 = my_perceptron(w3,X_test);
y_nhom1 = x3
y_nhom2 = my_perceptron(w3,[-1 x1 x2]')
y_nhom3 = my_perceptron(w4,[-1 x1 x2]')