class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        while(--n)
        {
            string next;
            char pre = result[0];
            int idx = 0;
            int num = 1;
            while( idx < result.size() )
            {
                while(result[idx+1] == result[idx])
                {
                    idx++,num++;
                }
                next.push_back(num+'0');
                next.push_back(result[idx++]);
                num = 1;
            }
            result = next;
        }
        return result;
    }
};
