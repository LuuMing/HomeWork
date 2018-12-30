class Solution {
public:
    int isPeak(vector<int>& num,int idx, int N)
    {
        if(idx == 0)
            return  (( idx <= N - 1) && (num[idx] > num[idx + 1]) ) || N == 1;
        else if( idx == N - 1 )
            return num[ idx ] >= num[idx - 1];
        else
            return num[idx] >= num[idx - 1] &&
                    num[idx] >= num[idx + 1];
    }
  
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        int N = nums.size();
        while(lo <= hi)
        {
            int mid = ( lo + hi ) / 2;
            if(isPeak(nums,mid,N))
                return mid;
            else
            {
                if( mid == 0 || ( nums[mid] - nums[ mid-1 ] > 0) )
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
    }
};
