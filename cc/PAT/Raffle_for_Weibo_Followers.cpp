
/*************************
	@date:18/8/7 20:13 ~ 20:37
	@author: LuMing
*************************/
#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set<string>s;
int M,N,S;
int main()
{
	cin >> M >> N >> S;
	char name[22];
	bool has = false;
	int num = 1;
	for(int i = 1; i <= M; i++)
	{
		scanf("%s",name);
		if(s.count(name))    // important operation
			S += 1;
		if(i==S && !s.count(name))
		{
			s.insert(name);
			printf("%s\n",name);
			S += N;
			has = true;
		}
	}
	if( !has)
		printf("Keep going...\n");


}
