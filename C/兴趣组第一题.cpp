#include<iostream>
using namespace std;
//定义所有情况函数： 
int ftc(int,char,int,char,int);//定义移动第一项的函数 
int stc(int,char,int,char,int);//定义移动第二项的函数 
int ttc(int,char,int,char,int);//定义移动第三项的函数 
int fiftc(int,char,int,char,int);//定义移动第五项的函数 
int fasts(int,char,int,char,int);//定义第一二项之间移动火柴棒的函数 
int fatts(int,char,int,char,int);//定义第一三项之间移动火柴棒的函数 
int fafits(int,char,int,char,int);//定义第一五项之间移动火柴棒的函数 
int safots(int,char,int,char,int);//定义第二四项之间移动火柴棒的函数 
int safits(int,char,int,char,int);//定义第二五项之间移动火柴棒的函数 
int tafits(int,char,int,char,int);//定义第三五项之间移动火柴棒的函数
 //用二元数组来存储一个用火柴棒表示的数字通过增加  减少  移动 可能的变形情况 ，若不能通过移动 增加 减少 火柴棒改变数字，则用-10来填补空缺，使原来的数字与它所对应的数组对应。 
int move[10][3]={6,9,-10,    -10,-10,-10,   3,-10,-10,    2,5,-10,     -10,-10,-10,   3,-10,-10,    0,9,-10,    -10,-10,-10,  -10,-10,-10,  0,6,-10};
int  add[10][3]={8,-10,-10,    -10,-10,-10,  -10,-10,-10,   9,-10,-10,   -10,-10,-10,   6,9,-10,      8,-10,-10,  -10,-10,-10,  -10,-10,-10,  8,-10,-10};
int  ajj[10][3]={-10,-10,-10,  -10,-10,-10,  -10,-10,-10,  -10,-10,-10,  -10,-10,-10,   -10,-10,-10,  5,-10,-10,  -10,-10,-10,   0,6,9,     5,3,-10};
int main(){
int a,b,c;char d,j;cout<<"   A       +       B         =        C"<<endl;cout<<"第一项   第二项   第三项   第四项   第五项"<<endl; cout<<"请输入等式:"<<endl;
while(cin>>a>>j>>b>>d>>c){
if(j=='+'){if(a+b==c){cout<<"正确等式"<<endl;continue;}}                                                   //先判断等式是否成立  成立则输出正确等式 
if(j=='-'){if(a-b==c){cout<<"正确等式"<<endl;continue;}}
if((a>9||a<0)||(b>9||b<0)||(c>9||c<0)){cout<<"超出范围"<<endl;continue;}                                   //执行改变火柴棒的函数 
int result0,result1,result2,result3,result4,result5,result6,result7,result8,result9;                       //定义result 0-9 来记录每种情况函数的返回值   通过改变后  等式成立则输出正确等式并将对应的result记为1   
result0=ftc(a,j,b,d,c);
result1=stc(a,j,b,d,c);
result2=ttc(a,j,b,d,c);
result3=fiftc(a,j,b,d,c);
result4=fasts(a,j,b,d,c);
result5=fatts(a,j,b,d,c);
result6=fafits(a,j,b,d,c);
result7=safots(a,j,b,d,c);
result8=safits(a,j,b,d,c);
result9=tafits(a,j,b,d,c);
if(result0==0&&result1==0&&result2==0&&result3==0&&result4==0&&result5==0&&result6==0&&result7==0&&result8==0&&result9==0){//尝试过所有情况后  若所有result都为0则输出不能完成 
cout<<"不能完成"<<endl;}
}                                                                                       
 return 0;  
}


	
int ftc(int a,char j,int b,char d ,int c){
if(j=='+'){
     for(int i=0;i<3;i++){if(move[a][i]+b==c){a=move[a][i];cout<<a<<j<<b<<d<<c<<"第一项移动一根火柴"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(add[a][i]+b==c){a=add[a][i];cout<<a<<j<<b<<d<<c<<"第一项添加一根火柴"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(ajj[a][i]+b==c){a=ajj[a][i];cout<<a<<j<<b<<d<<c<<"第一项移去一根火柴"<<endl;return 1;}}
}
if(j=='-'){
	 for(int i=0;i<3;i++){if(move[a][i]-b==c){a=move[a][i];cout<<a<<j<<b<<d<<c<<"第一项移动一根火柴"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(add[a][i]-b==c){a=add[a][i];cout<<a<<j<<b<<d<<c<<"第一项添加一根火柴"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(ajj[a][i]-b==c){a=ajj[a][i];cout<<a<<j<<b<<d<<c<<"第一项移去一根火柴"<<endl;return 1;}}
}return 0;
}



int stc(int a,char j,int b,char d,int c){
if(a+b==c){cout<<a<<'+'<<b<<d<<c<<"第二项添加一根火柴"<<endl;return 1;}
if(a-b==c){cout<<a<<'-'<<b<<d<<c<<"第二项移去一根火柴"<<endl;return 1;}                                
return 0;	
}



int ttc(int a,char j,int b,char d,int c){
	if(j=='+'){
     for(int i=0;i<3;i++){if(a+move[b][i]==c){b=move[b][i];cout<<a<<j<<b<<d<<c<<"第三项移动一根火柴"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a+add[b][i]==c){b=add[b][i];cout<<a<<j<<b<<d<<c<<"三项添加一根火柴"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a+ajj[b][i]==c){b=ajj[b][i];cout<<a<<j<<b<<d<<c<<"第三项移去一根火柴"<<endl;return 1;}}
}
if(j=='-'){
	 for(int i=0;i<3;i++){if(a-move[b][i]==c){b=move[b][i];cout<<a<<j<<b<<d<<c<<"第三项移动一根火柴"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a-add[b][i]==c){b=add[b][i];cout<<a<<j<<b<<d<<c<<"第三项添加一根火柴"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a-ajj[b][i]==c){b=ajj[b][i];cout<<a<<j<<b<<d<<c<<"第三项移去一根火柴"<<endl;return 1;}}
}return 0;	
}



int fiftc(int a,char j,int b,char d,int c){
if(j=='+'){
     for(int i=0;i<3;i++){if(a+b==move[c][i]){c=move[c][i];cout<<a<<j<<b<<d<<c<<"第五项移动一根火柴"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a+b==add[c][i]){c=add[c][i];cout<<a<<j<<b<<d<<c<<"第五项移动一根火柴"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a+b==ajj[c][i]){c=ajj[c][i];cout<<a<<j<<b<<d<<c<<"第五项移动一根火柴"<<endl;return 1;}}
}
if(j=='-'){
	 for(int i=0;i<3;i++){if(a-move[b][i]==c){b=move[b][i];cout<<a<<j<<b<<d<<c<<"第五项移动一根火柴"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a-add[b][i]==c){b=add[b][i];cout<<a<<j<<b<<d<<c<<"第五项添加一根火柴"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a-ajj[b][i]==c){b=ajj[b][i];cout<<a<<j<<b<<d<<c<<"第五项移去一根火柴"<<endl;return 1;}}
}return 0;		
}



int fasts(int a,char j,int b,char d,int c){
if(j=='+'){for(int i=0;i<3;i++){if(add[a][i]-b==c){a=add[a][i];cout<<a<<'-'<<b<<d<<c<<"第二项移动一根火柴给第一项"<<endl;return 1;}}}
if(j=='-'){for(int i=0;i<3;i++){if(ajj[a][i]+b==c){a=ajj[a][i];cout<<a<<'+'<<b<<d<<c<<"第一项移动一根火柴给第二项"<<endl;return 1;}}}
return 0;
	}



int fatts(int a,char j,int b,char d,int c){
if(j=='+')          {
for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
			if(add[a][i]+ajj[b][j]==c){a=add[a][i];b=ajj[b][j];cout<<a<<'+'<<b<<d<<c<<"第三项移动一根火柴给第一项"<<endl;return 1;} 
			if(ajj[a][i]+add[b][j]==c){a=ajj[a][i];b=add[b][j];cout<<a<<'+'<<b<<d<<c<<"第一项移动一根火柴给第三项"<<endl;return 1;}	}
			 }
					}
if(j=='-')                              {
for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
			if(add[a][i]-ajj[b][j]==c){a=add[a][i];b=ajj[b][j];cout<<a<<'-'<<b<<d<<c<<"第三项移动一根火柴给第一项"<<endl;return 1;} 
			if(ajj[a][i]-add[b][j]==c){a=ajj[a][i];b=add[b][j];cout<<a<<'-'<<b<<d<<c<<"第一项移动一根火柴给第三项"<<endl;return 1;}	}
			        }
				                    	}	return 0;  				                    
}



int fafits(int a,char j,int b,char d,int c){
if(j=='+')          {
for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
			if(add[a][i]+b==ajj[c][i]){a=add[a][i];c=ajj[c][j];cout<<a<<'+'<<b<<d<<c<<"第五项移动一根火柴给第一项"<<endl;return 1;} 
			if(ajj[a][i]+b==add[c][i]){a=ajj[a][i];c=add[c][j];cout<<a<<'+'<<b<<d<<c<<"第一项移动一根火柴给第五项"<<endl;return 1;}	}
			 }
					}
if(j=='-')                              {
for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
			if(add[a][i]-b==ajj[c][i]){a=add[a][i];c=ajj[c][j];cout<<a<<'-'<<b<<d<<c<<"第五项移动一根火柴给第一项"<<endl;return 1;} 
			if(ajj[a][i]-b==add[c][i]){a=ajj[a][i];c=add[c][j];cout<<a<<'-'<<b<<d<<c<<"第一项移动一根火柴给第五项"<<endl;return 1;}	}
			        }
				                    	}return 0;
}



int safots(int a,char j,int b,char d,int c){
if(j=='-'){if(a==b-c){cout<<a<<'='<<b<<'-'<<c<<"第四项移动一根火柴给第二项"<<endl;return 1;}}return 0;
}



int safits(int a,char j,int b,char d,int c){
if(j=='+'){for(int i=0;i<3;i++){if(a-b==add[c][i]){c=add[c][i];cout<<a<<'-'<<b<<d<<c<<"第二项移动一根火柴给第五项"<<endl;return 1;}}}
if(j=='-'){for(int i=0;i<3;i++){if(a+b==ajj[c][i]){c=ajj[c][i];cout<<a<<'+'<<b<<d<<c<<"第五项移动一根火柴给第二项"<<endl;return 1;}}}
return 0;
}



int tafits(int a,char j,int b,char d,int c){
if(j=='+')          {
for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
			if(a+ajj[b][j]==add[c][i])
			{c=add[c][i];b=ajj[b][j];cout<<a<<'+'<<b<<d<<c<<"第三项移动一根火柴给第五项"<<endl;return 1;} 
			if(a+add[b][j]==ajj[c][i])
			{c=ajj[c][i];b=add[b][j];cout<<a<<'+'<<b<<d<<c<<"第五项移动一根火柴给第三项"<<endl;return 1;}	}
			 }
					}
if(j=='-')                              {
for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
			if(a-ajj[b][j]==add[c][i]){c=add[c][i];b=ajj[b][j];cout<<a<<'-'<<b<<d<<c<<"第三项移动一根火柴给第五项"<<endl;return 1;} 
			if(a-add[b][j]==ajj[c][i]){c=ajj[c][i];b=add[b][j];cout<<a<<'-'<<b<<d<<c<<"第五项移动一根火柴给第三项"<<endl;return 1;}	}
			        }
				                    	}	return 0;
}
