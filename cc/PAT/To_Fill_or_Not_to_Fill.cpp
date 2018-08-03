#include<iostream>
#include<math.h>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
double Cmax;
double D;
double Davg;
int N;
bool cmp(const pair<double,double> & p1,const pair<double,double> &p2)
{
	return p1.second < p2.second;
}

int main()
{
	double total_cost = 0;
	double total_dist = 0;
	double C = 0;
	cin >> Cmax >> D >> Davg >> N;
	vector<pair<double,double>> station(N+1);                                //将终点看作一个station
	for(int i = 0; i < N;i++)
	{
		scanf("%lf%lf",&station[i].first,&station[i].second);
	}
	station[N].first = 0.0;
	station[N].second = D;
	sort(station.begin(),station.end(),cmp);
	if(abs(station[0].second -0.0) > 1e-10 )                                  //如果起点没有加油站
	{
		printf("The maximum travel distance = %.2f",0.00);
		return 0;
	}
	int target = 0;
	for(int i = 0; station[i].second != D;i = target)
	{

		target = (i+1>= N?N:i+1);                            //初始target 为离当前最近的station
		bool lesser = false;
		for(int j = i + 1; j < N + 1; j++)                             //找target,  P.S. i = 当前station
		{
			if(station[j].second-station[i].second <= Cmax * Davg) //首先确保能到达
			{							
				if(station[j].first > station[i].first)       //如果比当前station贵，找最贵中相对便宜的station
				{
					if(station[j].first < station[target].first)
					{
						target = j;
					}		
				}
				else                                           //一旦比当前station便宜，确定它为target
				{
					target = j;
					lesser = true;
					break;
				}
			}
		}
		if(station[target].second - station[i].second > Davg * Cmax)  //若从i无法到达target
		{
			total_dist = station[i].second + Cmax * Davg ;                 
			printf("The maximum travel distance = %.2f",total_dist);
			return 0;
		}
		if(lesser)               				        //如果找到更低价格的station
		{
			if(C >= (station[target].second - station[i].second) / (Davg))//油够，直接开过去
			{
				C -= (station[target].second - station[i].second) / Davg;
			}
			else							     //否则，加最少的油
			{
				total_cost += ( (station[target].second - station[i].second )/(Davg) - C ) * station[i].first;
				C = 0;
			}	
		}
		else                      					    //如果没找,加满油,找到最便宜能到达的站
		{
			total_cost += ( Cmax-C )*station[i].first;    //加满油
			C = Cmax;                                     //加满油
			C -= (station[target].second - station[i].second) / Davg; //耗油
		}
		total_dist = station[target].second;        //车开到target station
	}
	printf("%.2f",total_cost);
}
