#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
	vector<int> child;
	string id;
	int weight;		
};
bool mycomp(const vector<int> n1,const vector<int> n2)
{	
	for(auto i = n1.begin() , j = n2.begin(); i != n1.end() && j != n2.end();i++,j++)
	{
		if(*i == *j)
		{
			continue;
		}
		else 
			return *i>*j;
	}
	return false;
}

vector<vector<int>> find_all_tree(int s,node* Nodes)
{
	vector<vector<int>> all_path;
	for(auto i = Nodes[s].child.begin(); i!= Nodes[s].child.end();i++)
	{
		if(Nodes[*i].child.empty())
		{
			vector<int> path;
			path.push_back(*i);
			all_path.push_back(path);
		}
		else
		{
			vector<vector<int>> sub_path = find_all_tree(*i,Nodes);
			for(auto j = sub_path.begin(); j != sub_path.end();j++)
			{
				vector<int> path;
				path.push_back(*i);
				path.insert(path.end(),(*j).begin(),(*j).end());
				all_path.push_back(path);
			}
		}
	}
	return all_path;
}

int main()
{
	int N = 0;
	int M = 0;
	int S = 0;
	int id = 0;
	int child_id = 0;
	int K = 0;
	cin >> N;
	cin >> M;
	cin >> S; 
	node * Nodes = new node[N];
	for(int i = 0; i < N ;i++)
	{
		cin >> Nodes[i].weight;
	}
	for(int i = 0;i < M;i++)
	{
		cin >> id;
		cin >> K;
		for(int i = 0;i < K;i++)
		{
			cin >> child_id;
			Nodes[id].child.push_back(child_id);
		}
	}
	if(N==1&&(S==Nodes[0].weight))
	{
		cout<<S;                    //排除1个节点的情况 
	}
	
	vector<vector<int>> all_tree = find_all_tree(0,Nodes);
	if(all_tree.empty())
	{
		return 0;
	}
	vector<vector<int>> sequence;
//	int k = 1;
//	for(auto &i:all_tree)
//	{
//		cout<<"path"<<k<<':';
//		for(auto &j:i)
//		{
//			cout<<j<<' ';
//		}
//		k++;
//		cout<<endl;
//	}
	for(auto i = all_tree.begin(); i != all_tree.end(); i++)
	{
		int sum = Nodes[0].weight;
		for(auto j = (*i).begin();j != (*i).end(); j++)
		{
			sum += Nodes[*j].weight;
		}
		if(sum == S)
		{
			vector<int> t;
			t.push_back(Nodes[0].weight);
			for(auto k = (*i).begin(); k != (*i).end(); k++)
			{
				t.push_back(Nodes[*k].weight);
			}
			sequence.push_back(t);	
		}
	}
	if(sequence.empty())
	{
		return 0;
	}
	sort(sequence.begin(),sequence.end(),mycomp);
	
	for(auto i = sequence.begin(); i != (sequence.end()-1) ;i++)
	{
		for(auto j = (*i).begin(); j != ((*i).end()-1);j++)
		{
			cout<<*j<<' ';
		}
		cout<< *((*i).end()-1)<<endl;
	}
	for(auto i = (*(sequence.end()-1)).begin(); i !=(*(sequence.end()-1)).end()-1;i++)
	{
		cout<<*i<<' ';
	}
	cout << *((*(sequence.end()-1)).end()-1);

	return 0;
}
