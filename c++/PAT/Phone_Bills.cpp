#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
vector<int> charge;
int day_charge;
struct Time
{
	int month;
	int dd;
	int hh;
	int mm;
	Time (int a,int b,int c, int d)
	{
		month = a;
		dd = b;
		hh = c;
		mm = d;
	}
	Time(){}
};
bool cmp  (const Time &T1,const Time & T2)
{
	string t1,t2;
 	t1+= to_string(T1.month);
	t1+= to_string(T1.dd);
	t1+= to_string(T1.hh);
	t1+= to_string(T1.mm);
	t2 += to_string(T2.month);
	t2 += to_string(T2.dd);
	t2 += to_string(T2.hh);
	t2 += to_string(T2.mm);
	return t1 < t2;
}
double compute_cost(Time s,Time e)
{
	
	double cost = 0;
	cost -= s.dd * day_charge;
	cost -= s.mm * charge[s.hh];
	cost += e.dd * day_charge;
	cost += e.mm * charge[e.hh];
	for(int i = s.hh; i !=e.hh; i++)
	{
		cost += 60 * charge[i];
	}
	return cost/100;
}
int compute_time(Time s,Time e)
{
	return (e.dd-s.dd)*1440 + (e.hh-s.hh)*60+(e.mm-s.mm);
}
struct person
{
	vector<Time> on_line;
	vector<Time> off_line;
	vector<pair<Time,Time>>  record;
	int month;
	double total_cost()
	{
		double total = 0;
		for(auto &i:this->record)
		{
			total += compute_cost(i.first,i.second);
		}
		return total;
	}
	
};

map <string,person> p;
int N;
int main()
{
	charge.resize(24);
	day_charge = 0;
	for(int i = 0; i < 24; i++)
	{
		scanf("%d",&charge[i]);
		day_charge += charge[i];
	}
	day_charge *= 60;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		string id,line;
		Time time;
		cin >> id;
		scanf("%d:%d:%d:%d ",&time.month,&time.dd,&time.hh,&time.mm);
		cin >> line;
		if(line=="on-line")
		{
			p[id].on_line.push_back(time);
		}
		else
		{
			p[id].off_line.push_back(time);
		}
		p[id].month = time.month;
	}
	for(auto &i:p)
	{
		sort(i.second.on_line.begin(),i.second.on_line.end(),cmp);
		sort(i.second.off_line.begin(),i.second.off_line.end(),cmp);
	}
	for(auto &i:p)
	{
		while((!i.second.on_line.empty()) && (!i.second.off_line.empty()))
		{
			if(cmp(*(i.second.on_line.end()-1), *(i.second.off_line.end()-1)))
			{
				i.second.record.push_back(make_pair(*(i.second.on_line.end()-1),*(i.second.off_line.end()-1)));
				i.second.on_line.erase(i.second.on_line.end()-1);
				i.second.off_line.erase(i.second.off_line.end()-1);
			}
			else
			{
				i.second.on_line.erase(i.second.on_line.end()-1);
			}		
		}
					
	}
	for(auto &i:p)
	{
		cout << i.first<<' ';
		printf("%02d\n",i.second.month);
		for(auto j = i.second.record.begin(); j!= i.second.record.end();j++)
		{
			printf("%02d:%02d:%02d %02d:%02d:%02d ",j->first.dd,j->first.hh,j->first.mm,j->second.dd,j->second.hh,j->second.mm);
			cout << compute_time(j->first,j->second) << " $";
			printf("%.2f\n",compute_cost(j->first,j->second));
		}
		printf( "Total amount: $%.2f\n",i.second.total_cost());	
	}
	
}

