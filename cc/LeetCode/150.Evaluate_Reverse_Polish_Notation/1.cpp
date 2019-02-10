class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(auto & token : tokens)
        {
            if( isdigit(token.back()) )
                s.push(token);
            else
            {
                int a = stoi(s.top()); s.pop();
                int b = stoi(s.top()); s.pop();
                int next = 0;
                switch(token[0])
                {
                    case '+':
                        next = a + b;
                        break;
                    case '-':
                        next = b - a;
                        break;
                    case '*':
                        next = a * b;
                        break;
                    case '/':
                        next = b / a;
                        break;
                }
                s.push(to_string(next));
            }
        }
        return stoi(s.top());
    }
};