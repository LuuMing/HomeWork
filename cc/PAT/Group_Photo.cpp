/*****************
	@author: LuMing
	@date:	18/8/21 21:00~22:00
********************/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define MAX 10001
using namespace std;
struct person
{
	string name;	
	int h;
};
vector<vector<person> > row;
person p[MAX];
int N,K;
bool cmp(const person & p1,const person & p2)
{
	if(p1.h != p2.h)
	{
		return p1.h  > p2.h;
	}
	else
		return p1.name < p2.name;
}
void arrange(vector<person> & p)
{
	int middle = p.size() / 2;
	int middle_left = middle -1;
	int middle_right = middle + 1;
	vector<person> tmp = p;
	p[middle] = p[0];
	int cnt = 1;
	while(cnt < p.size())
	{
		if(middle_left >= 0)
		{
			p[middle_left] = tmp[cnt];
			cnt++;
			middle_left--;
		}
		if(middle_right < p.size())
		{
			p[middle_right] = tmp[cnt];
			cnt++;
			middle_right++;
		}
	}

}
int main()
{
	int rear_num,i,r,cnt,j;
	cin >> N >> K;
	rear_num = N -(N/K * K) + (N/K);
	for( i = 0; i < N;i ++)
	{
		cin >> p[i].name>>p[i].h;
	}
	sort(p,p+N,cmp);
	vector<person> tmp;
	for(i = 0; i < rear_num;i++)
	{
		tmp.push_back(p[i]);
	}
	row.push_back(tmp);
	for(  r = 1; r < K;r++)
	{
		vector<person> v;
		for( cnt = 0; cnt < N/K;i++,cnt++)
		{
			v.push_back(p[i]);
		}
		row.push_back(v);
	}
	for( i = 0; i < row.size(); i++)
	{
		arrange(row[i]);
		for(j = 0;j < row[i].size();j++)
		{
			cout << row[i][j].name;
			if(j != row[i].size() - 1)
				cout << ' ';
		}
		cout << endl;
	}
}