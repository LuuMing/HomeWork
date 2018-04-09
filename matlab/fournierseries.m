function [X,w] = fournierseries(x,T0,N)
syms t
for k = 1:N
    X1(k) = int(x*exp(-j*2*pi*(k-1)*t/T0),t,0,T0)/T0; %intËã»ý·Ö¡Òf(t)* e^(-jn¦¸t) dt  
    X(k) = subs(X1(k));
    w(k) = (k-1)* 2 * pi/T0;                           %w = 2n¦Ð/T
end