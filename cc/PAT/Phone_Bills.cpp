#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int day_charge;
vector<int> charge;
struct record
{
	string ID,line;
	int month,dd,hh,mm;
	int total;
};
string get_time(record r)
{
	char buffer[12];
	sprintf(buffer,"%02d:%02d:%02d:%02d",r.month,r.dd,r.hh,r.mm);
	return string(buffer);
}
bool cmp(const record &c1,const record &c2 )
{
	if(c1.ID!=c2.ID)
	{
		return c1.ID < c2.ID;
	}
	else
	{
		return get_time(c1) < get_time(c2);
	}
}
double compute_cost(const record & s,const record & e)
{
	double cost = 0;
        cost -= s.dd * day_charge;
        cost -= s.mm * charge[s.hh];
        cost += e.dd * day_charge;
        cost += e.mm * charge[e.hh];
        for(int i = 0; i != s.hh; i++)
        {
                cost -= 60 * charge[i];
        }
	for(int i = 0; i != e.hh;i++)
	{
		cost += 60*charge[i];
	}
        return cost/100;
	
	cout << endl;
}
int main()
{
	int N = 0;
	map<string,vector<pair<record,record>>> round;
	charge.resize(24);
	day_charge = 0;
	for(int i = 0; i < 24;i++)
	{
		cin >> charge[i];
		day_charge += charge[i];
	}
	day_charge *= 60;
	cin  >> N;
	vector<record> records(N);
	for(int i = 0; i < N;i++)
	{
		cin >> records[i].ID;
		scanf("%d:%d:%d:%d",&records[i].month,&records[i].dd,&records[i].hh,&records[i].mm);
		cin >> records[i].line;
		records[i].total = records[i].dd * 24 *60+records[i].hh*60+records[i].mm;
	}
	sort(records.begin(),records.end(),cmp);
	for(int i = 1; i < records.size(); i++)
	{
		if(records[i].ID == records[i-1].ID && records[i].line == "off-line" && records[i-1].line == "on-line")
		{
			round[records[i].ID].push_back(make_pair(records[i-1],records[i]));
		}
	}
	for(auto &i:round)
	{
		double total_cost = 0;
		printf("%s %02d\n",i.first.c_str(),i.second[0].first.month);
                for(auto j:i.second)
                {
			total_cost += compute_cost(j.first,j.second);
                        printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",j.first.dd,j.first.hh,j.first.mm,j.second.dd,j.second.hh,j.second.mm,j.second.total-j.first.total,compute_cost(j.first,j.second));
                }
                printf("Total amount: $%.2f\n",total_cost);

	}
}
