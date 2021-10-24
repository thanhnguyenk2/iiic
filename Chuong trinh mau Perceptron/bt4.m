X = [-1 -1 -1 -1 -1 -1 -1 -1 -1;...
      0.3  0.35 0.28  0.8 0.7 1 0.8 1.2 1.6;...
      0.5 0.45 0.35 0.75 0.78 0.7 0.4 0.5 0.45];
  
X3 = [-1 -1 -1 -1;...
      0 0 1 1 ;...
      1 0 1 0];
D1 = [0 0 0 0 0 0 1 1 1];
D2 = [1 1 1 0 0 0 0 0 0];
D3 = [0 1 0 0];
D4 = [1 0 0 0];
w1 = train_perceptron(X,D1)
w2 = train_perceptron(X,D2)
w3 = train_perceptron(X3,D3)
w4 = train_perceptron(X3,D4)
X_test = [-1 0.9 0.4]';
x1 = my_perceptron(w1,X_test);
x2 = my_perceptron(w2,X_test);
y1_giuong = x1
y2_ban = my_perceptron(w3,[-1 x1 x2]')
y3_ghe = my_perceptron(w4,[-1 x1 x2]')