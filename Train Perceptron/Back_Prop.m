clc
clear
%%
% x_1 = [-1 0.5 -0.2]';
% v1_1 = [0.2 -0.1 0.6]';
% v2_1 = [-0.2 0.1 0.4]';
% w_1 = [0.2 0.2 -0.3]';
% n = 0.4;
% d1=0.5;

x_1 = [0 0.4 -0.2]';
v1_1 = [0 0.4 0.2]';
v2_1 = [0 -0.5 0.3]';
w_1 = [0 0.2 -0.6]';
n = 0.2;
d1=0.7;

%% Ham kich hoat
%Lop an
syms a b ;
f_an = logsig(a);
f_an_diff = diff(f_an,a);
%Lop ra
f_ra = tansig(b);
f_ra_diff = diff(f_ra,b);
%% Lop an
neth1_1=v1_1'*x_1;
neth2_1=v2_1'*x_1;
z1_1 = round(double(subs(f_an, neth1_1)),3);
z2_1 = round(double(subs(f_an, neth2_1)),3);
%%
z_o = [0;z1_1;z2_1];            %% them bias vao z out
%% Lop ra
neto1_1 = w_1'*z_o;
y_1=round(double(subs(f_ra, neto1_1)),3);

%% Back
%Lop ra

xichmaO_1 = [d1-y_1]*round(double(subs(f_ra_diff,neto1_1)),3);
w_2 = w_1 + n*xichmaO_1*z_o;

%Lop an


xichmaH1_1 = xichmaO_1*w_1(2)*round(double(subs(f_an_diff,z1_1)),3); %tansig dao ham
xichmaH2_1 = xichmaO_1*w_1(3)*round(double(subs(f_an_diff,z2_1)),3);
v1_2 = v1_1 + n * xichmaH1_1*x_1;
v2_2 = v2_1 + n * xichmaH2_1*x_1;
E = 1/2*(d1 - y_1)^2;






