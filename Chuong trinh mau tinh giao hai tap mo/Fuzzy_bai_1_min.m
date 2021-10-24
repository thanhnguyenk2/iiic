% 
close all
y = 0:0.01:30;
muyy_VS = hlt_hinhthang(y,0,0,0,3);
muyy_S = hlt_hinhthang(y,0,3,3,8);
muyy_ME = hlt_hinhthang(y,3,8,8,16);
muyy_L = hlt_hinhthang(y,8,16,16,30);
muyy_VL = hlt_hinhthang(y,16,30,30,30);
plot(y,muyy_VS,'r',y, muyy_S, 'g', y, muyy_ME, 'b',y, muyy_L, 'm',y, muyy_VL, 'c');

hold on
% Gia tri muy(x1)
x1_var = 20;
x1_LO = hlt_hinhthang(x1_var,0,0,0,15);
x1_ME = hlt_hinhthang(x1_var,0,15,15,40);
x1_HI = hlt_hinhthang(x1_var,15,40,60,60);
% Gia tri muy(x2)
x2_var = 12;
x2_LO = hlt_hinhthang(x2_var,0,0,0,10);
x2_ME = hlt_hinhthang(x2_var,0,10,10,15);
x2_HI = hlt_hinhthang(x2_var,10,15,15,20);
x2_VH = hlt_hinhthang(x2_var,15,20,30,30);
% Suy luan
result = zeros(size(y));

beta1 = min(x1_LO,x2_LO);
y1 = Implication_MIN(beta1, muyy_VL);
result = Or_MAX(result, y1);

beta2 = min( x1_LO,x2_ME);
y2 = Implication_MIN(beta2, muyy_ME);
result = Or_MAX(result, y2);

beta3 = min(x1_LO,x2_HI);
y3 = Implication_MIN(beta3, muyy_S);
result = Or_MAX(result, y3);

beta4 = min(x1_LO,x2_VH);
y4 = Implication_MIN(beta4, muyy_VS);
result = Or_MAX(result, y4);

beta5 = min(x1_ME,x2_LO);
y5 = Implication_MIN(beta5, muyy_VL);
result = Or_MAX(result, y5);

beta6 = min(x1_ME,x2_ME);
y6 = Implication_MIN(beta6, muyy_L);
result = Or_MAX(result, y6);

beta7 = min(x1_ME,x2_HI);
y7 = Implication_MIN(beta7, muyy_S);
result = Or_MAX(result, y7);

beta8 = min(x1_ME,x2_VH);
y8 = Implication_MIN(beta8, muyy_VS);
result = Or_MAX(result, y8);

beta9 = min(x1_HI,x2_LO);
y9 = Implication_MIN(beta9, muyy_VL);
result = Or_MAX(result, y9);

beta10 = min(x1_HI,x2_ME);
y10 = Implication_MIN(beta10, muyy_L);
result = Or_MAX(result, y10);

beta11 = min(x1_HI,x2_HI);
y11 = Implication_MIN(beta11, muyy_ME);
result = Or_MAX(result, y11);

beta12 = min(x1_HI,x2_VH);
y12 = Implication_MIN(beta12, muyy_VS);
result = Or_MAX(result, y12);
plot(y, result,'k--.');
legend('VS', 'S', 'ME','L','VL', 'result');
