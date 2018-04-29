#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;
int adj[2005][2005];
bool visited[2005];
map<string,int> output;
stringstream ss;
map<int,string> int2str;
map<string,int> str2int;
int weight[2005];
int N;
int K;
vector<int> temp;
bool cmp(int & a,int &b)
{
	if(weight[a]!= weight[b])
	return weight[a] > weight[b];
	else 
		return int2str[a] < int2str[b];
}
int total = 0;
void dfs(int v)
{	
	visited[v] = true;
	temp.push_back(v);
	for(int i = 1; i <= int2str.size(); i++)
	{
		if(!visited[i] && adj[v][i] != 0)
		{
			dfs(i);
		}
	}
}
void list()
{
	int num = 0;
	for(int i = 1; i <= int2str.size();i++ )
	{
		temp.clear();
		total = 0;
		if(!visited[i])
		{
			dfs(i);
		}
		for(auto i:temp)
			total += weight[i];
		total/= 2;
		if(total > K && temp.size() > 2)
		{
			num++;
			sort(temp.begin(),temp.end(),cmp);
			output[int2str[temp[0]]] = temp.size();
		}
	}
	if(num==0)
		cout << 0;
	else
	{
		cout << num << endl;
		for(auto i :output)
		{
			cout << i.first <<' ' << i.second << endl;
		}
	}
}
int main()
{
	cin >> N >> K;

	int num = 0;
	for(int i = 0; i < N; i++)
	{
		string name1,name2; int time;
		cin >> name1 >> name2 >> time;
		if(!str2int.count(name1) )
		{
			str2int[name1] = ++ num;
			int2str[num] = name1;
		}
		if(!str2int.count(name2))
		{
			str2int[name2] = ++ num;
			int2str[num] = name2;
		}
	
			adj[str2int[name1]][str2int[name2]] += time;
			adj[str2int[name2]][str2int[name1]] += time;
		weight[str2int[name1]] += time;
		weight[str2int[name2]] += time;
	}
	
	list();
}
