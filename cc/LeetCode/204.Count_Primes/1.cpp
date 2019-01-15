class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> isprime(n, true);
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(!isprime[i])
                continue;
            for(int j = i * i; j < n; j+= i)
                isprime[j] = false;
        }
        for(int i = 2; i < n ;i++)
        {
            if(isprime[i])
                cnt++;
        }
        return cnt;
    }
};