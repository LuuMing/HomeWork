/*
	智能分词

分词是指将一个字符串分割成词语序列，其中所有词语都来自事先指定的词汇表。例如：
有字符串"github"，以及词汇表["git", "hub"]，那么分词方式为:"git hub"。

分词可能有多重方式，例如字符串"asdfjkl"，以及词汇表["as", "asd", "df", "fjkl", "jkl"]，可能有两种分词方法:"as df jkl"、"asd fjkl"。先定义每种分词方法的合理性得分为：分词方案中每个单词长度的平方和。例如上述两种分词方案的得分分别为 2^2 + 2^2 + 3^2 = 17，以及 3^2 + 4^2 = 25。

现给出词汇表（均为小写字母，单词最长50字符，最多10个万单词），以及一句话（均为小写字母，最长10万字符），找出最合理的分词方案。若有多种得分相同的最合理方案，输出长词尽量靠前的方案。例如"ab cdef"与"abcd ef"这两种最优方案得分相同，输出"abcd ef"。
*/
#include<iostream>
#include<vector>
#include<math.h>
#include<string.h>
using namespace std;
vector<string> v[300];
char word[60];
int idx = 0;
vector<string> tmp,result;
int weight = 0;
int max_weight =0;
int L = 0;
char end;
void dfs(char start)
{
	if( idx == L && weight >= max_weight)
	{
		if(weight > max_weight)
		{
			max_weight = weight;
			result = tmp;
			return;
		}
		else
		{
			int i = 0, j = 0;
			for(; i < result.size() && j < tmp.size(); i++,j++)
			{
				if(result[i].size() < tmp[j].size())
				{	
					result = tmp;
					return ;
				}
			}
		}
	}
	for(int i = 0; i < v[word[idx]].size(); i++)
	{
		string & t = v[word[idx]][i];
		tmp.push_back(t);
		idx += t.size();
		weight += pow(t.size(),2);
		dfs(t[t.size() - 1]);	
		weight -= pow(t.size(),2);
		idx -= t.size();
		tmp.pop_back();
	}
}
int main()
{
	scanf("%s",word);
	L = strlen(word);
	int N; cin >> N;
	for(int i = 0; i< N;i++)
	{
		string s; cin >> s;
		v[s[0]].push_back(s);
	}
	dfs(word[0]);
	for(int i = 0; i< result.size(); i++)
	{
		cout << result[i];
		if( i != result.size() - 1)
			cout << ' '; 
	}
}
