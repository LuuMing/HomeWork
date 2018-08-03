#include<iostream>
using namespace std;
struct num
{
	bool pos = true;
	string yi;
	string wan;
	string base;
}n;
char cte[10][10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
void say(string num)
{
	while(num[0]=='0')
	{
		num.erase(num.begin());
	}
	switch(num.size())
	{
		case 4 :
			cout << cte[num[0]-'0']<<"Qian "
			<<   cte[num[1]-'0']<<"Bai "<<
			cte[num[2]-'0']<<"Shi "<<
			cte[num[3]-'0'];       break;
		case 3 :
			cout<<cte[num[0]-'0']<<"Bai "<<
			cte[num[1]-'0']<<"Shi "<<
			cte[num[2]-'0'];       break; 
		case 2 :
			cout << cte[num[0]-'0']<<"Shi "<<
			cte[num[1]-'0'];          break;
		case 1 :          
			cout << cte[num[0]-'0'];	break;
		case 0 :  cout << "ling";        break;
	}
}
int main()
{
	
	string input;
	cin >> input;
	string tmp;
	if(input[0] == '-')
	{
		n.pos = false;
		input.erase(input.begin());		
	}
	if(input.size()<4)
	{
		n.base = input;		
	}
	else if(input.size() >=4 & input.size() <= 8)
	{
		n.base = input.substr(input.size()-5,4);
		n.wan = input.substr(0,input.size()-4);	
	}
	else
	{
		n.base = input.substr(input.size()-5,4);
		n.wan = input.substr(input.size()-8,4);	
		n.yi  =  input.substr(0,input.size()-8);
	}
	if(!n.pos)
	{
		cout << "Fu ";
	}		
	say(n.yi); cout << " Yi ";
	say(n.wan);cout << " Wan ";
	say(n.base);
}