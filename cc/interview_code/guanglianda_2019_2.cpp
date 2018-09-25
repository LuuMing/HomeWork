/*
	根据击杀输出段位
*/
#include<iostream>
using namespace std;
int main()
{
	string position[] = {"on a Killing Spree","Dominating","a Mega-Kill",
"Unstoppable","Wicked Sick","a M-m-m-m....Monster Kill","Godlike","Beyond Godlike"};
	int cnt = 0;
	string s; cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'D')
		{
			cnt = 0;
		}
		else
			cnt++;
	}
	if(cnt <= 2)
		cout << "a Foolish Man";
	else
	{
		cout << position[cnt - 3];
	}
	return 0;
}
