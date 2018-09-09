#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<map>
// 若存在字符串 T,使得字符串 A 中 'a' - 'z' 替换为 T中第 1-26 个，替换完后 A与 B相同 ，则称 A 与 B相似。
//求A中共有多少个与B相似的子串。 
//测试输入 
 //ababcb
//xyx
//测试输出 
// 3  
//说明：原串 -> 映射
//aba ->xyx    bab -> xyx   bcb -> yxy
using namespace std;
/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
map<char,char> m; 
int solve(string S, string T) {
	int cnt = 0;
    for(int i=0; i <= S.size() - T.size() ;i++)
    {
    	bool flag = true;
        string tmp = S.substr(i,T.size());
        for(int j = 0;j < tmp.size() ;j ++)
        {
            if(!m.count(T[j]))
            {
            	m[T[j]] = tmp[j]; 
			}
			else if(m[T[j]] == tmp[j] )
			{
				continue;
			}
			else
			{
				flag = false;
				break;
			}
        }
        if(flag)
            cnt++;
        m.clear();
    }
    cout << cnt << endl;
    return cnt;

}
/******************************结束写代码******************************/


int main() {
    int res;

    string _S;
    getline(cin, _S);
    string _T;
    getline(cin, _T);
    
    res = solve(_S, _T);
    cout << res << endl;
    
    return 0;

}

