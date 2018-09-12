class Solution {
    vector<string> result;
    vector<string> m ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(string digits,int idx,string r)
    {
        if(idx >= digits.size())
            return;
        for(int i = 0; i < m[digits[idx]-'0'].size(); i++)
        {
            string tmp = r + m[digits[idx]-'0'][i];
            if(idx == digits.size() - 1)
            {
                result.push_back(tmp);
            }
            dfs(digits,idx+1,tmp);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        dfs(digits,0,"");
        return result;
    }
};
