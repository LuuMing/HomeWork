[x1 fs]=wavread('c:\outputfile.wav');
x1 = x1(:,1);
%% 降采样  --start
l=length(x1);%采样点数
t=l/fs;%采样时间
fs =0.2* fs;                        %重新调整采样频率
l2 = t*fs;
B=l/l2; 
for i=1:l2
x2(i,:)=x1(round(i*B),:);%重新采样
end

%% 滤波   --start
t=0:1/fs:(length(x2)-1)/fs;
wp=0.1*pi;ws=0.12*pi;               %数字角频率
Rp=1;Rs=15;
Fs=0.5*fs;Ts=1/Fs;
wp1=2/Ts*tan(wp/2);                 %将模拟指标转换成数字指标
ws1=2/Ts*tan(ws/2); 
[N,Wn]=buttord(wp1,ws1,Rp,Rs,'s');  %选择滤波器的最小阶数
[Z,P,K]=buttap(N);                  %创建butterworth模拟滤波器
[Bap,Aap]=zp2tf(Z,P,K);
[b,a]=lp2lp(Bap,Aap,Wn);
[bz,az]=bilinear(b,a,Fs);           %用双线性变换法实现模拟滤波器到数字滤波器的转换
[H,W]=freqz(bz,az);                 %绘制频率响应曲线
figure(1)
plot(W*Fs/(2*pi),abs(H))
grid
xlabel('频率／Hz')
ylabel('频率响应幅度')
title('Butterworth')
f1=filter(bz,az,x2);
figure(2)
subplot(2,1,1)
plot(t,x2)                          %画出滤波前的时域图

sound(x2,fs);
wavwrite(x2,fs,'c:\欠采样滤波前.wav');
title('滤波前的时域波形');
subplot(2,1,2)
plot(t,f1);                         %画出滤波后的时域图
title('滤波后的时域波形');
sound(f1,fs);                    %播放滤波后的信号
wavwrite(f1,fs,'c:\欠采样滤波后.wav');
F0=fft(f1,1024);
f=fs*(0:511)/1024;
figure(3)
y2=fft(x2,1024);
subplot(2,1,1);
plot(f,abs(y2(1:512)));             %画出滤波前的频谱图
title('滤波前的频谱')
xlabel('Hz');
ylabel('fuzhi');
subplot(2,1,2)
F1=plot(f,abs(F0(1:512)));          %画出滤波后的频谱图
title('滤波后的频谱')
xlabel('Hz');
ylabel('fuzhi');
