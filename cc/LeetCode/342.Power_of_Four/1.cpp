class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 1)
            return true;
        else if(num == 0)
            return false;
        if( num % 4 == 0 )
        {
            return isPowerOfFour(num / 4);
        }
        else
            return false;
    }
};
