/*************************************
@Date:2018/8/3
@Author: LuMing
@说明:
今天我们看到的阿里巴巴提供的任何一项服务后面都有着无数子系统和组件的支持，子系统之间也互相依赖关联，其中任意一个环节出现问题都可以对上游链路产生影响。小明做为新人接收到的第一个任务就是去梳理所有的依赖关系，小明和每个系统的负责人确认了依赖关系，记录下调用对应系统的耗时，用这些数据分析端到端链路的数目和链路上最长的耗时。
输入： 小明搜集到的系统耗时和依赖列表
5 4	//表示有5个系统和4个依赖关系
3	//调用1号系统耗时 3 ms
2	//调用2号系统耗时 2 ms
10	//调用3号系统耗时 10 ms
5	//调用4号系统耗时 5 ms
7	//调用5号系统耗时 7 ms
1 2	// 2号系统依赖1号系统
1 3	// 3号系统依赖1号系统
2 5	// 2号系统依赖5号系统
4 5	// 4号系统依赖5号系统

输出： 调用链路的数目 和最大的耗时， 这里有三条链路1->2->5, 1->3, 4->5，最大的耗时是1到3的链路 3+10 = 13，无需考虑环形依赖的存在。
3 13
**************************************/
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> v;
vector<int> w;
vector<int>  indegree;
int N,M; 
vector<vector<int>> result;
void dfs(int root,vector<int> t)
{
	t.push_back(root);
	if(v[root].size() == 0 && t.size() > 1)
	{
		result.push_back(t);
	}
	for(int i = 0; i < v[root].size();i++)
	{
		dfs(v[root][i],t);
	}
}
int main()
{
	cin >> N >> M;
	v.resize(N+1);
	w.resize(N+1);
	indegree.resize(N+1);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i = 0; i < M;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		v[a].push_back(b);
		indegree[b]++;
	}
	for(int i = 1; i <= N;i++)
	{
		vector<int> tt;
		if(indegree[i]== 0)
		{
			dfs(i,tt);
		}
	}
	cout << result.size() << ' ';
	int Max = -1;
	for(int i = 0; i < result.size();i++)
	{
		int total = 0;
		for(auto a : result[i])
		{
			total += w[a];
		}
		if( total > Max)
		{
			Max = total;
		}
	}
	cout << Max;
}
