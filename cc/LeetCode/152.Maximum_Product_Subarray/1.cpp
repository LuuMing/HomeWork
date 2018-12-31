class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int runningProd = 1;
        int maxProd = 1;
        int minProd = 1;
        int best = INT_MIN;
        for(auto & n:nums)
        {
            if( n < 0 )
                swap(maxProd,minProd);
            maxProd = max(n,maxProd * n);
            minProd = min(n,minProd * n);
            best = max(best,maxProd);
        }
        
        return best;
    }
};
