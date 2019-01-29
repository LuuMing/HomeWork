class Solution {
public:
    int addDigits(int num) {
        while( num / 10 )
        {
            int step = 0;
            while(num)
            {
                step += num % 10;
                num /= 10;
            }
            num = step;
        }
        return num;
    }
};
