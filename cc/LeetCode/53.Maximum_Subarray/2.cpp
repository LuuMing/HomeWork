class Solution {
public:
    vector<int>  *nums;
    int divide(int l,int r)
    {
    	if( l  > r || l == r) return nums->at(l);
	            int mid = (l + r) / 2;
        int m_l = divide(l,mid);
	    int m_r = divide(mid + 1, r);
        int ml_crosMid = -9999;
	    int mr_crosMid = -9999;
	    int t = 0;
	    for(int i = mid; i >= 0; i--)
	    {
	    	t += nums->at(i);
	    	if( t > ml_crosMid)
	    		ml_crosMid = t;
	    }
	    t = 0;
	    for(int i = mid + 1; i <= r; i++)
	    {
	    	t += nums->at(i);
	    	if( t > mr_crosMid )
	    		mr_crosMid = t;
	    }
	    return max(max(m_l,m_r),ml_crosMid + mr_crosMid);
}
    int maxSubArray(vector<int>& nums) 
    {
        this->nums = &nums;
        return divide(0,nums.size() - 1);
    }
};
