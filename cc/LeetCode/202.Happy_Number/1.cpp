class Solution {
public:
    unordered_set<int> s;
    bool isHappy(int n) {
        if(n == 1)
            return true;
        else
        {
            int  t = 0;
            while(n)
            {
                t += pow(n % 10,2);
                n /= 10;
            }
            if(s.count(t))
                return false;
            else
            {
                s.insert(t);
                return isHappy(t);
            }
        }
    }
};
