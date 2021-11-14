Ts=0.01;   %chu ky lay mau
N=20000;   %so mau du lieu
Umin = -1;
Umax = 1;
PWmin = 50;
PWmax = 150;
k1=1;
k2=1;
uu = zeros(1,N);
while k2 < N
    PW = PWmin + round(rand*(PWmax-PWmin));
    k2 = k1 + PW;
    if k2 > N
        k2 = N;
    end
    uu(k1:k2) = Umin + rand*(Umax-Umin);
    k1 = k2;
end
t = (1:N)*Ts;
plot(uu)
sig = [t;uu];
save Pendulum_Input sig
