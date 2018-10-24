class Solution {
public:
    double myPow(double x, int n) {
        long nn = n;
        cout << nn <<' ' <<x<< endl;
        if( nn < 0) 
        {
            nn = -nn;
            x = 1.0 / x;
        }
        if(nn == 0)
            return 1.0;
        else
        {
            if( nn % 2 == 0)
                return  myPow(x * x,nn / 2);
            else
                return x*myPow(x*x,nn / 2);
        }
    }
};
