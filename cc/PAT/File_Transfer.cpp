#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> pre;

int find(int i)
{
	if (i == pre[i])
		return pre[i];
	else
	{
		pre[i] = find(pre[i]);
		return pre[i];
	}

}
void merge(int a, int b)
{
	int set_A = find(a);
	int set_B = find(b);
	if(set_A != set_B)
	{
		pre[set_A] = set_B; 
	}
}
int main()
{
	cin >> N;
	pre.resize(N+1);
	for(int i = 1; i <= N;i++)
	{
		pre[i] = i;
	}
	char q = '0';
	int a;
	int b;
	while(1)
	{
		cin >> q;
		if(q == 'I')
		{
			cin >> a >> b;
			merge(a,b);
		}
		else  if(q == 'C')
		{
			cin >> a >> b;
			int set_A = find(a);
			int set_B = find(b);
			if(set_A == set_B)
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else
		{
			break;
		}
	}
	int single = 0;
	for(int i = 1; i <= N;i++)
	{
		if(pre[i] == i)
		{
			single ++;
		}
	}
	if(single == 1)
	{
		cout << "The network is connected.";
	}
	else
	{
		cout << "There are " << single<<" components.";
	}
}

