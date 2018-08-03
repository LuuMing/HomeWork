#include<iostream>
#include<math.h>
using namespace std;
struct croco
{
	double x;
	double y;
	bool visited = false;
};
croco crocos[101];
int N;
double D;
bool reach(int i,int j)
{
	double a = pow(crocos[i].x-crocos[j].x,2);
	double b = pow(crocos[i].y-crocos[j].y,2);
	double c = pow(D,2);
	if( a+b < c)
		return true;
	else return false;
}
bool DFS (int s)
{
	bool answer = false;
	crocos[s].visited = true;
	if(crocos[s].x - D <= -50 || crocos[s].x + D >=50 || crocos[s].y -D <=-50 || crocos[s].y+D >=50)
	{
		return true;
	}
	else
	{
		for(int i = 0; i < N; i++)
		{
			if(reach(s,i)&&!crocos[i].visited)
			{
				
				answer =  DFS(i);
			}
			if(answer)
			{
				return true;
			}
		}
	}
	return false;
}
bool ListComponent()
{
	bool result;
	for(int i = 0; i < N; i++)
	{
		if(!crocos[i].visited && pow(crocos[i].x,2)+pow(crocos[i].y,2)<= pow(7.5+D,2))
		{
			result = DFS(i);
		}
		if(result)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	cin >> N >> D;
	for(int i = 0; i < N; i++)
	{
		cin >> crocos[i].x >> crocos[i].y;
	}
	if(D >= 42.5)
	{
		cout  << "Yes";
		return 0;
	}
	bool result = ListComponent();
	result?cout <<"Yes":cout << "No";
}
