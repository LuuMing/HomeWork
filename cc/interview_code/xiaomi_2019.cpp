/*
	@author: LuMing
	@date: 18/9/20 20:37
说明：给定字符串 text 与匹配模式 pattern
匹配 text 中含有 pattern 的最小区间，非连续
输出在 text 中的起始位置与终止位置
sample: 
abaacxbcbbbbacc cbc
4 7
abc x
-1 -1
*/
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
unordered_map<char,int> m,m2;
int main()
{
	int size = 0;
	char text[10000];
	char pattern[1000];
	while(scanf("%s",text)!=0)
	{
		int l = -1, r = -1;
		int idx = 0;
		scanf("%s",pattern);
		size = strlen(text);
		int gap = 9999;
		for(int i = 0; i < size; i++)
		{
			int tmp_l = -1,tmp_r = -1;
			if(text[i] == pattern[idx])
			{	
				int count = strlen(pattern);
				int tmp_idx = idx+1;
				for(int j = i + 1; j < size;j++ )
				{
					if(text[j] == pattern[tmp_idx])
					{
						tmp_idx ++;
					}
					if(tmp_idx > count- 1 && j - i < gap)
					{
						gap = j - i;
						l = i;
						r = j;
						break;
					}
				}
			}
	
		}
		cout << l << ' ' << r << endl;
	}
}
