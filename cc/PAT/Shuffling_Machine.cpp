#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct card
{
	int num;
	char C;
};
vector<card> cards;
vector<card> new_c;
int main()
{
	cards.resize(55); new_c.resize(55);	
	for(int i = 1; i <= 54; i++)
	{
		cards[i].num = i % 13;
		if(cards[i].num==0)
			cards[i].num = 13;
		if( (i-1) / 13 == 0)
		{
			cards[i].C = 'S';
		}
		else if((i-1)/13 == 1)
		{
			cards[i].C = 'H';
		}
		else if ((i-1)/13 == 2)
		{
			cards[i].C ='C';
		}
		else if((i-1)/13 == 3)
			cards[i].C ='D';
		else
			cards[i].C ='J';
	}
	int N; cin >> N;
	int shuff[55];
	for(int i = 1; i <= 54;i++) scanf("%d",&shuff[i]);
	for(int j = 0; j < N;j++)
	{
		for(int i = 1; i <=54;i++)
		{
			new_c[shuff[i]] = cards[i];
		}
		cards = new_c;
	}
	for(int i = 1;i <= 54;i++)
	{
		if(i!=54)
		printf("%c%d ",cards[i].C,cards[i].num);
		else
		printf("%c%d",cards[i].C,cards[i].num);
	}
}
