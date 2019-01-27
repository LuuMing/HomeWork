class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int lo = 0, hi = height.size() - 1;
        while( lo <= hi )
        {
            if( height[lo]  height[hi] )
                swap(lo,hi);
            {
                int i = lo;
                while( height[i] <= height[lo] && i <= hi )
                {
                    sum += height[lo] - height[i];
                    i++;
                }
                lo = i;
            }
            else
            {
                int i = hi;
                while( height[i] <= height[hi] && i >= lo )
                {
                    sum += height[hi] - height[i];
                    i--;
                }
                hi = i;
            }
        }
        return sum;
    }
};
