class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty())
            return 0;
        int pre = timeSeries[0];
        int cnt = 0;
        for(int i = 1; i < timeSeries.size(); i++){
            if( timeSeries[i] - pre > duration){
                cnt += duration;
            }
            else{
                cnt += timeSeries[i] - pre;
            }
            pre = timeSeries[i];
        }
        cnt += duration;
        return cnt;
    }
};
