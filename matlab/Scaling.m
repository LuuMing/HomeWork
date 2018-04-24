syms t w
for tau = 0:0.01:10
x = heaviside(t + tau/2) - heaviside(t - tau/2);
X = fourier(x);
figure(1)
subplot(211)
ezplot(x,[-3 3]);
axis([-3 3 -0.1 1.1])
grid;ylabel('x_1(t)');
xlabel('t')
subplot(212)
ezplot(X,[-50 50]);
axis([-50 50 -1 5])
grid; ylabel('X_1(\Omega)');
Xlabel('\Omega')
 frame=getframe(gcf);
 im=frame2im(frame);
   [I,map]=rgb2ind(im,256);
    if tau==0;
        imwrite(I,map,'D:\test.gif','gif','Loopcount',inf,...
            'DelayTime',0.1); 
    else
        imwrite(I,map,'D:\test.gif','gif','WriteMode','append',...
            'DelayTime',0.1); 
    end
end