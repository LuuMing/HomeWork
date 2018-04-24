i = 10;    %迭代次数
r = 10;     %范围
dt = 0.01;  %间隔
w = 1;      %角频率
%%%%%%%%%%%%%%%%%%
n = 1;
t = -r:dt:r;
bn = 4/(n*pi);
y = bn*sin(w*t);
plot(t,y);
a = input('请按任意键继续');
for ii = 1:i
    xlabel({'第',num2str(ii),'次'});
    hold on;
    n = n + 2;
    bn = 4/(n*pi);
    yn = bn*sin(n*w*t);
    comet(t,yn);
    y = y + yn;
    hold off;
    axis equal;
    plot(t,y);
    xlabel({'第',num2str(ii),'次'});
    pause(1);    
end