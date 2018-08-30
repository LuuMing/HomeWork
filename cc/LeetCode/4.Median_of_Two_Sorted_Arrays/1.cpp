/***************
	@author: LuMing
	@date: 18/8/30 08:24~08:42
***************/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0,j = 0;
        while( i < nums1.size()  && j < nums2.size())
        {
                if(nums1[i] > nums2[j])
                {
                        result.push_back(nums2[j++]);
                }
                else
                {
                        result.push_back(nums1[i++]);
                }
        }
                for(;i < nums1.size(); i++)
                        result.push_back(nums1[i]);
                for(;j < nums2.size(); j++)
                {
                        result.push_back(nums2[j]);
                }
                double ans;
                int t = result.size();
                if(result.size() % 2 == 0)
                {
                        ans = (double)(result[t / 2] + result[t/2 - 1]) / 2.0;
                }
                else
                {
                        ans = result[result.size() / 2];
                }
                return ans;
    }
};
