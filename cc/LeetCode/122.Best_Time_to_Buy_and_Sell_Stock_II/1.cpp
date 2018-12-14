class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int current = prices[0];
        int total = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] > current)
            {
                total += prices[i] - current;
                current = prices[i];
            }
            else
            {
                current = prices[i];
            }
        }
        return total;
    }
};
