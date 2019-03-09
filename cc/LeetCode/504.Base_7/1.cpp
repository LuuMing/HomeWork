class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        string ret;
        bool sign = false;
        if(num < 0)
        {
            sign = true;
            num = -num;
        }
        while(num)
        {
            ret = (char)( num % 7 + '0') + ret;
            num /= 7;
        }
        if(sign) ret = '-' + ret;
         return ret;
    }
};
