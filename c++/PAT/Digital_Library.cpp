#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct book
{
	string info[6];
};
bool mycmp(const book &b1,const book &b2)         //sort by num
{
	return b1.info[0] < b2.info[0];
}
int main()
{
	int N;
	int M;
	scanf("%d\n",&N);
	string output;
	vector<book> Books(N);
	for(int i = 0; i < N; i++)
	{
		getline(cin,Books[i].info[0]);
		getline(cin,Books[i].info[1]);
		getline(cin,Books[i].info[2]);
		getline(cin,Books[i].info[3]);
		getline(cin,Books[i].info[4]);
		getline(cin,Books[i].info[5]);
	}
	sort(Books.begin(),Books.end(),mycmp);
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		int n;
		bool find = false;
		string query;
		scanf("%d: ",&n);
		getline(cin,query);
		output +=(to_string(n)+": "+query);
		if (n!=3)                                         //not keywords, query must match book's item;
		{
			for(auto &i:Books)
			{	
				if(i.info[n]==query)
				{
					output += ("\n"+i.info[0]);
					find = true;
				}
			}
		}
		else                                              //Keywords, query only have to be the part of book's keywords.
		{
			for(auto &i:Books)
			{
				if(i.info[n].find(query)!=-1)
				{
					output += ("\n"+i.info[0]);
					find = true;
				}
			}
		}
		if(!find)
		{
			output += "\nNot Found";
		}
		output += "\n";
	}
	output.erase(output.end()-1);                            //erase extra Enter.
	cout << output;
}
