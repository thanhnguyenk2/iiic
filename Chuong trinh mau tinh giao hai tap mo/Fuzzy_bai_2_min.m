% 
close all
y = 0:0.01:60;
muyy_VS = hlt_hinhthang(y,0,8,8,12);
muyy_S = hlt_hinhthang(y,8,12,12,20);
muyy_ME = hlt_hinhthang(y,12,20,20,40);
muyy_L = hlt_hinhthang(y,20,40,40,60);
muyy_VL = hlt_hinhthang(y,40,60,60,60);
plot(y,muyy_VS,'r',y, muyy_S, 'g', y, muyy_ME, 'b',y, muyy_L, 'm',y, muyy_VL, 'c');

hold on
% Gia tri muy(x1)
x1_var = 40;
x1_S = hlt_hinhthang(x1_var,0,0,0,50);
x1_ME = hlt_hinhthang(x1_var,0,50,50,100);
x1_L = hlt_hinhthang(x1_var,50,100,100,100);
% Gia tri muy(x2)
x2_var = 80;
x2_NG = hlt_hinhthang(x2_var,0,0,0,50);
x2_ME = hlt_hinhthang(x2_var,0,50,50,100);
x2_G = hlt_hinhthang(x2_var,50,100,100,100);

% Gia tri muy(x3)
x3_var = 30;
x3_L = hlt_hinhthang(x3_var,0,0,0,50);
x3_ME = hlt_hinhthang(x3_var,0,50,50,100);
x3_H = hlt_hinhthang(x3_var,50,100,100,100);
%---------------
x1 = zeros(1,3);
x1(1) = x1_S;
x1(2) = x1_ME;
x1(3) = x1_L;
x2 = zeros(1,3);
x2(1) = x2_NG;
x2(2) = x2_ME;
x2(3) = x2_G;
x3 = zeros(1,3);
x3(1) = x3_L;
x3(2) = x3_ME;
x3(3) = x3_H;
% Suy luan -------------------------------------
result = zeros(size(y));
beta = zeros(1,27);
i = 1;
for k=1:3
    for l=1:3
        for m=1:3
            beta(i) = min(x1(k),x2(l));
            beta(i) = min(beta(i), x3(m));
            i = i + 1;
        end
    end
end

%1
y1 = Implication_MIN(beta(1), muyy_VS);
result = Or_MAX(result, y1);


y2 = Implication_MIN(beta(2), muyy_S);
result = Or_MAX(result, y2);


y3 = Implication_MIN(beta(3), muyy_ME);
result = Or_MAX(result, y3);

%4
y4 = Implication_MIN(beta(4), muyy_S);
result = Or_MAX(result, y4);


y5 = Implication_MIN(beta(5), muyy_S);
result = Or_MAX(result, y5);


y6 = Implication_MIN(beta(6), muyy_ME);
result = Or_MAX(result, y6);

%7
y7 = Implication_MIN(beta(7), muyy_S);
result = Or_MAX(result, y7);


y8 = Implication_MIN(beta(8), muyy_ME);
result = Or_MAX(result, y8);


y9 = Implication_MIN(beta(9), muyy_L);
result = Or_MAX(result, y9);

%10
y10 = Implication_MIN(beta(10), muyy_S);
result = Or_MAX(result, y10);


y11 = Implication_MIN(beta(11), muyy_S);
result = Or_MAX(result, y11);


y12 = Implication_MIN(beta(12), muyy_ME);
result = Or_MAX(result, y12);
j = j + 1;
%13
y13 = Implication_MIN(beta(13), muyy_S);
result = Or_MAX(result, y13);


y14 = Implication_MIN(beta(14), muyy_ME);
result = Or_MAX(result, y14);


y15 = Implication_MIN(beta(15), muyy_ME);
result = Or_MAX(result, y15);

%16
y16 = Implication_MIN(beta(16), muyy_S);
result = Or_MAX(result, y16);


y17 = Implication_MIN(beta(17), muyy_ME);
result = Or_MAX(result, y17);


y18 = Implication_MIN(beta(18), muyy_L);
result = Or_MAX(result, y18);

%19
y19 = Implication_MIN(beta(19), muyy_ME);
result = Or_MAX(result, y19);


y20 = Implication_MIN(beta(20), muyy_ME);
result = Or_MAX(result, y20);


y21 = Implication_MIN(beta(21), muyy_L);
result = Or_MAX(result, y21);

%22
y22 = Implication_MIN(beta(22), muyy_ME);
result = Or_MAX(result, y22);


y23 = Implication_MIN(beta(23), muyy_L);
result = Or_MAX(result, y23);


y24 = Implication_MIN(beta(24), muyy_VL);
result = Or_MAX(result, y24);

%25
y25 = Implication_MIN(beta(25), muyy_ME);
result = Or_MAX(result, y25);


y26 = Implication_MIN(beta(26), muyy_VL);
result = Or_MAX(result, y26);


y27 = Implication_MIN(beta(27), muyy_VL);
result = Or_MAX(result, y27);

plot(y, result,'k--.');
legend('VS', 'S', 'ME','L','VL', 'result');    
