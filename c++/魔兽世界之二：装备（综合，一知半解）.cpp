#include<iostream>
#include<string> 
#include<cstdio>
using namespace std;
const int WARRIOR_NUM=5;
const int WEAPON_NUM=3;
class Headquarter;
class Warrior
{
	private:
		Headquarter* pHeadquarter;//每个勇士有指向他自己所在基地的一个指针 
		int kindNo;//武士种类编号 
		int weaponNum;//武器数量 
		int weaponNo[2];//存储的武器的种类 
		int no;
		double morale;//士气 
		int loyalty;//忠诚度 
	public:
		static string names[WARRIOR_NUM];//names包含物种武士的名字 
		static string weapons[WEAPON_NUM];//weapon包含3种武器的名字 
		static int initialLifeValue[WARRIOR_NUM];//initiallifevalue五个武士初始的生命值 
		Warrior(Headquarter*p,int no_,int kindNo_);//构造函数，第一个基地的指针，第二个为no，第三个为种类 
		void PrintResult(int nTime);//打印nTime时间的信息 
		void PrintInformation();  
};
//HQ有Warrior,Warrior指向HQ，逻辑合理 
class Headquarter
{
	private:
		int totalLifeValue;//每个基地有总生命值 
		bool stopped;//是否停止 
		int totalWarriorNum;//总武士数量 
		int color;//颜色 红or蓝 
		int curMakingSeqIdx;//当前造武士的序列 
		int warriorNum[WARRIOR_NUM];//存放武士的数量 
		Warrior *pWarriors[1000];//指向warrior的指针数组 
	public:
		friend class Warrior;
		static int makingSeq[2][WARRIOR_NUM];//武士的制作顺序序列   两行 
		void Init(int color_,int lv);//初始化 
		~Headquarter();//析构函数 
		int Produce(int nTime);//生产武士 
		string GetColor();//返回"red" 或"blue" 
};
Warrior::Warrior(Headquarter *p,int no_,int kindNo_)
{
	no=no_;//武士的序号 
	kindNo=kindNo_;//武士的种类 
	pHeadquarter=p;//武士的归属 
	if(kindNo!=3&&kindNo!=4)
	{
		if(kindNo==1)
		weaponNum=2;
		else weaponNum=1;
	}//如果是1类武士，可以拥有两件武器，如果是2类武士，可以拥有一件武器 
	else weaponNum=0;
	for (int i=0;i<weaponNum;i++)//Warrior基类的共有特性   
	weaponNo[i]=(no+i)%3;
	if(kindNo==0)
	morale=(double)p->totalLifeValue/initialLifeValue[0];
	else morale=0;
	if(kindNo==3)
	loyalty=p->totalLifeValue;
	else loyalty=0;
} 
void Warrior::PrintResult(int nTime)
{
	string color=pHeadquarter->GetColor() ;//得到武士的基地的颜色 
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",nTime,color.c_str(),names[kindNo].c_str(),no,initialLifeValue[kindNo],pHeadquarter->warriorNum[kindNo],names[kindNo].c_str(),color.c_str());
} 

void Warrior::PrintInformation() 
{
	if(kindNo==0) printf("It has a %s,and it's morale is %.2f\n",weapons[weaponNo[0]].c_str(),weapons[weaponNo[1]].c_str(),morale);
	if(kindNo==1) printf("It has a %s and a %s\n",weapons[weaponNo[0]].c_str(),weapons[weaponNo[1]].c_str());
	if(kindNo==2) printf("It has a %s\n",weapons[weaponNo[0]].c_str());
	if(kindNo==3) printf("It's loyalty is %d\n",loyalty);
}
void Headquarter::Init(int color_,int lv)
{
	color=color_;
	totalLifeValue=lv;
	totalWarriorNum=0;
	stopped=false;
	curMakingSeqIdx=0;
	for(int i=0;i<WARRIOR_NUM;i++)
	warriorNum[i]=0;
}

Headquarter::~Headquarter()
{
	for(int i=0;i<totalWarriorNum;i++)
	{
		delete pWarriors[i];
	}
}

int Headquarter::Produce(int nTime)
{
	if(stopped)
	return 0;
	int searchingTimes=0;
	while(Warrior::initialLifeValue [makingSeq[color][curMakingSeqIdx]]>totalLifeValue&&searchingTimes<WARRIOR_NUM)
	{
	curMakingSeqIdx=(curMakingSeqIdx+1)%WARRIOR_NUM;
	searchingTimes++;
	}
	int kindNo=makingSeq[color][curMakingSeqIdx];
	if(Warrior::initialLifeValue [kindNo]>totalLifeValue)
	{
		stopped=true;
		if(color==0)
		printf("%03d red headquarter stops making warriors\n",nTime);
		else
		printf("%03d blue headquarter stops making warriors\n",nTime);
		return 0;
	}
//制作士兵 
totalLifeValue-=Warrior::initialLifeValue [kindNo];
curMakingSeqIdx=(curMakingSeqIdx+1)%WARRIOR_NUM;
pWarriors[totalWarriorNum]=new Warrior(this,totalWarriorNum+1,kindNo);
warriorNum[kindNo]++;
pWarriors[totalWarriorNum]->PrintResult(nTime);
pWarriors[totalWarriorNum]->PrintInformation() ;
totalWarriorNum++;
return 1; 
}

string Headquarter::GetColor() 
{
	if(color==0)
	return "red";
	else 
	return "blue";
} 
 string Warrior::names[WARRIOR_NUM]={"dragon","ninja","iceman","lion","wolf"};
 string Warrior::weapons[WEAPON_NUM]={"sword","bomb","arrow"};
 int Warrior::initialLifeValue [WARRIOR_NUM];
 int Headquarter::makingSeq[2][WARRIOR_NUM]={{2,3,4,1,0},{3,0,1,2,4}};
 int main()
 {
 	int t;
	int m;
 	Headquarter RedHead,BlueHead;
 	scanf("%d",&t);
 	int nCaseNo=1;
 	while(t--)
	 {        

	 	scanf("%d",&m);
	 	for(int i=0;i<WARRIOR_NUM;i++)
	 		scanf("%d",&Warrior::initialLifeValue [i]);
	 	RedHead.Init(0,m);
		BlueHead.Init(1,m);
		int nTime=0;
	     printf("Case:%d\n",nCaseNo++); 

		while(true)
		{
			int tmp1=RedHead.Produce(nTime);
			int tmp2=BlueHead.Produce(nTime);
			if(tmp1==0&&tmp2==0)
			break;
			nTime++;  
		} 
	 }

 
 
 
 
 
 
 }
