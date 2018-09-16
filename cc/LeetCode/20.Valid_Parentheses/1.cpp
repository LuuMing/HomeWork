class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '('||s[i] == '['||s[i] == '{')
                S.push(s[i]);
            else
            {
                if( S.empty())
                    return false;
                char t = S.top();
                S.pop();
                if( (s[i] == ')' && t=='(') || (s[i] == ']' && t=='[') || (s[i] == '}' && t=='{'))
                    ;
                else
                    return false;
            }
        }
        cout << s.size() << endl;
        if(S.empty())
            return true;
        else
            return false;
    }
};
