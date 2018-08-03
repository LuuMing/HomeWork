#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<math.h>
using namespace std;
int N;
struct person
{
	string name;
	char gender;
	int grade;

};

class cmp
{
	private:
		int mode;
	public:
		cmp(int m)
		{
			mode = m;
		}
		bool operator()(const pair<string,person> & p1,const pair<string,person> & p2)
		{
			if(mode == 0)
			{
				return p1.second.grade < p2.second.grade; //if mode == 0,sort ascend
			}
			else
			{
				return p1.second.grade > p2.second.grade;//else, sort descend
			}
		}
};

unordered_map<string,person> boys,girls;
vector<pair<string,person>>  sort_vector_boy,sort_vector_girl;
int main()
{
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		int grade;
		string name,id;
		char gender;
		cin >> name >> gender >> id >>grade;
		person p = {name,gender,grade};     //!!!  the inital of struct
		if(gender == 'M')
		{
			boys[id] = p;
		}
		else
		{
			girls[id] = p;
		}
	}
	for(auto &i:boys)
	{
		sort_vector_boy.push_back(make_pair(i.first,i.second));
	}
	for(auto &i:girls)
	{
		sort_vector_girl.push_back(make_pair(i.first,i.second));
	}
	sort(sort_vector_boy.begin(),sort_vector_boy.end(),cmp(0));
	sort(sort_vector_girl.begin(),sort_vector_girl.end(),cmp(1));
	int flag = 0;
	if(!sort_vector_girl.empty())
	{
		flag++;
		cout << sort_vector_girl[0].second.name <<' '<<sort_vector_girl[0].first <<endl;
	}
	else
	{
		cout <<"Absent"<<endl;
	}
	if(!sort_vector_boy.empty())
	{
		flag ++;
		cout << sort_vector_boy[0].second.name <<' '<<sort_vector_boy[0].first <<endl;
	}
	else
	{
		cout <<"Absent"<<endl;
	}
	if(flag == 2)
	{
		cout << abs(sort_vector_girl[0].second.grade -sort_vector_boy[0].second.grade);
	}
	else
	{
		cout <<"NA";
	}
}
