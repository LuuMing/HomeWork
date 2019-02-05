class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        if( n == 1)
           return true;
         else
         {
             if( n % 2 == 0)
                 return isPowerOfTwo( n >> 1);
             else
                 return false;
         }
    }
};
