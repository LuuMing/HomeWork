#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;	
int num[] = {8,2,3,4,5,7,0,1,6,9};	
bool cmp(const int & n1, const int &n2)
{
	return num[n1] < num[n2];
}
int main()
{
	int table[10];

	for(int i = 0; i < 10;i++)
		table[i] = i;
	sort(table,table+10,cmp);
	for(int i = 0; i < 10;i++)	cout << num[i] << ' ';	
	cout << endl;
	for(int i = 0; i < 10;i++)	cout << table[i] << ' ';
}
