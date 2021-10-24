X = [-1 -1 -1 -1 -1 -1 -1 ;...
     3595 4285 4585 6403 6600 11990 10810;...
     1595 1695 1760 2032 2000 2490 2500;...
      1480 1435 1760 2070 2600 3415 3500];
  
X3 = [-1 -1 -1;...
      0 0 1 ;...
      1 0 0];
D1 = [0 0 0 0 0 1 1];
D2 = [1 1 1 0 0 0 0];
D3 = [0 1 0];
D4 = [1 0 0];
w1 = train_perceptron(X,D1)
w2 = train_perceptron(X,D2)
w3 = train_perceptron(X3,D3)
w4 = train_perceptron(X3,D4)
X_test = [-1 3790 1605 1460]';
x1 = my_perceptron(w1,X_test);
x2 = my_perceptron(w2,X_test);
y1_hon16cho = x1
y2_12_16_cho = my_perceptron(w3,[-1 x1 x2]')
y3_duoi9cho = my_perceptron(w4,[-1 x1 x2]')