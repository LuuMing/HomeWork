class Solution {
vector<string> result;
int N;
void dfs(int n,string tmp,int n_l,int n_r)
{
	if(n_l == N && n_r == N)
	{
        	result.push_back(tmp);
   	}
    	else if(n > N)
        	return;
	tmp += "(";
	n_l ++;
	string t = tmp;
	int cnt = 0;
	for(int i = n_r; i <= n_l; i++)
	{
        	dfs(n+1,t,n_l,n_r+cnt);
		t+=")";
		cnt ++;
	}
}
public:
    vector<string> generateParenthesis(int n) {
	N = n;
	string tmp;
	dfs(1,tmp,0,0);
        return result;
    }
};
