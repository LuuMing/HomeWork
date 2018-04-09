%%产生周期信号
clc;clear;
syms t
tao = 2;    %%τ        
N = 20;     %%谐波数量
T = 4 * tao;
m = (heaviside(t+tao/2)-heaviside(t-tao/2));
for i = -5:5
    if i == 0
        continue;
    end
    m = m+(heaviside(i*T+t+tao/2)-heaviside(i*T+t-tao/2));
end
figure(1)
ezplot(t,m,[-5*T,5*T]);
[X,W] = fournierseries(m,T,N);
X1 = [conj(fliplr(X(2:N))) X];
W1 = [-conj(fliplr(W(2:N))) W];
figure(2)
stem(W1,X1);  %包络线

hold on;
w = min(W1):0.01:max(W1);
y = tao/T * (sin(w*tao/2)./(w*tao/2));%Sa函数
plot(w,y);    