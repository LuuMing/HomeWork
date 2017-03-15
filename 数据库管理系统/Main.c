#include<stdio.h>
#include <windows.h>
void dataSearch();   
void Renew();
void View();
void screenup();
void adminMainScreen();
void studentMainScreen();
char database[30][10];       //用二维数组保存学生 
char adminId[]={"teacher"};   // 初始化管理员账号密码 
char adminPw[]={"123456"};    //
char studentId[]={"student"}; //初始化学生账号密码 
char studentPw[]={"654321"};  //
FILE* fp1;
FILE* fp2;


int main()
										{

	int i,j;
fp1=fopen("database.txt", "r");       //用database.txt保存学生数据 


 
for (i = 0; i < 30; i++)
    {
      fscanf(fp1,"%s",database[i]); //读文件内容到database 
    }
    fclose(fp1);


	
system("cls");			
int power=0;char temId[10],temPw[10];int n=0;	 //根据输入的用户名密码判断权限 

while(power==0)
{system("cls");
screenup();
printf("                      请输入账号(管理员:teacher，用户:student)\n");
scanf("%s",temId);
printf("                      请输入密码(管理员:123456),用户(654321)\n");
scanf("%s",temPw);

if(strcmp(temId,adminId)==0&&strcmp(temPw,adminPw)==0)                
{power=1;}

else if(strcmp(temId,studentId)==0&&strcmp(temPw,studentPw)==0)
{power=2;}

else 
{
printf("账号密码错误\n");  Sleep(1000);	continue;
}
system("cls");
}

if(power==1)                                 //权限是1的时候进入管理员界面 
{
 adminMainScreen();
}


if(power==2)                                  //权限是2的时候进入用户界面 
{
studentMainScreen();
}


										}



void adminMainScreen()                       //管理员功能函数 
{
	int n;
	screenup();
	printf("1.学生数据查询\n2.学生数据修改\n3.注销\n4.全体学生数据一览\n\n\n\n\n\n\n\n\n请输入编号:");
	scanf("%d",&n);
	while(1)
	{
	if(n==1)
	{
	dataSearch();
	adminMainScreen();	
	}    
	else if(n==2)   Renew();
	else if(n==3)   main();
	else if(n==4) 	View();
	scanf("%d",&n);
	}
}

void dataSearch()                        //查找数据功能函数
{

	system("cls");
	screenup();
	char tem[10];
	printf("请输入要查询的序号或姓名或姓氏,(输入back返回):");
	scanf("%s",tem);
	while(strcmp(tem,"back")!=0)
	{
		system("cls");
		screenup();
		datasearchMain(tem);
		
		scanf("%s",tem);
	}
	system("cls");

	
}
void datasearchMain(char tem[])
{	
	int i,j;char c[10];
	printf("请输入要查询的序号或姓名或姓氏,(输入back返回):");

	if('0'<tem[0]&&tem[0]<='9'||'0'<tem[0]&&tem[0]<='9'&&'0'<tem[1]&&tem[1]<'9')
	{
			c[0]=tem[0];
			c[1]=tem[1];
			i=atoi(c);
			if(i<=9)
			printf("\n姓名:%s,学号15100410%i\n",database[i-1],i);
			else
			printf("\n姓名:%s,学号1510041%i\n",database[i-1],i);
	}
	else 
	{
		for(i=0;i<30;i++)
			for(j=0;j<10;j++)
			{	
			if(strlen(tem)<=2)
			{
				if(database[i][j]==tem[0]&&database[i][j+1]==tem[1]&&i<=9)
				printf("\n姓名:%s,学号15100410%i\n",database[i],i+1);
				else if
				(database[i][j]==tem[0]&&database[i][j+1]==tem[1]&&i>9)
				printf("\n姓名:%s,学号1510041%i\n",database[i],i+1);
			}
			
				else if(database[i][j]==tem[0]&&database[i][j+1]==tem[1]&&database[i][j+2]==tem[2]&&database[i][j+3]==tem[3]&&i<=9)
				printf("\n姓名:%s,学号15100410%i\n",database[i],i+1);
				else if
				(database[i][j]==tem[0]&&database[i][j+1]==tem[1]&&database[i][j+2]==tem[2]&&database[i][j+3]==tem[3]&&i>9)
				printf("\n姓名:%s,学号1510041%i\n",database[i],i+1);
			}
		
	}
	
}

void studentMainScreen()                  // //用户功能函数  
{
    int n;
	screenup();
	printf("1.学生数据查询\n2.注销\n\n\n\n\n\n\n\n\n请输入编号:");
	scanf("%d",&n);
	while(1)
	{
    if(n==1) 	
	{
		dataSearch();
		studentMainScreen();
	}	
	
    else if(n==2) 
	main(); 

	scanf("%d",&n);
	}
 
}

void Renew()                             //录入功能函数 
{  
	system("cls");
	screenup();
	int num=0,t1,t2,i;char tem[10],t;
	printf("请输入要修改学生的序号或学号输入-1结束:");

	while(num!=-1)
								{
	scanf("%d",&num);
	if(num==-1) break;
	else if(num>151004100)
	{
		t1=num%10;
		t2=(num/10)%10;
		num=t1+t2*10;
	}
	else if(num<30);
	else 
	{
	printf("输入范围错误\n");
	continue;
	}
								
	printf("请输入修改后的名字:\n");
	scanf("%s",tem);
	if(num<9)
	printf("将编号为15100410%d修改为%s?请输入Y/N:",num,tem);
	else	
	printf("将编号为1510041%d修改为%s?请输入Y/N:",num,tem);
	scanf("%c",&t);
	scanf("%c",&t);
	if(t=='y'||t=='Y')
	{
	strcpy(database[num-1],tem);
	printf("修改成功!\n请输入要修改学生的序号或学号输入-1结束:");
	}
	else continue;
	}
	fp2=fopen("database.txt", "w");
	for (i = 0; i < 30; i++)
    {
      fprintf(fp2,"%s\n",database[i]); 
    }
    fclose(fp2);
    system("cls");
 adminMainScreen();   
}




void screenup()                                  //输出标题函数 
{
	printf("\n\n                        *******学生数据管理系统******\n\n\n");
}
void View()                                      //查看数据功能函数 
{
	int i;
	for(i=0;i<30;i++)
	{	if(i<=8)
		printf("学号:15100410%d  姓名%s\n",i+1,database[i]);
		else 
		printf("学号:1510041%d  姓名%s\n",i+1,database[i]);
	}
	printf("请输入编号:");
}

