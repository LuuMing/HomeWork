class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
       int lo = 0, hi = nums.size() - 1,middle;
        while( lo <= hi )
        {
             middle = ( lo + hi ) / 2;
            if(nums[middle] == target)
                return middle;
            if( nums[middle] > nums[hi] ) // exist rotate
            {
                if( target < nums[middle] && target >= nums[lo] )
                    hi = middle - 1;
                else
                    lo = middle + 1;
            }
            else if( nums[middle] < nums[lo] ) // another case exist rotate
            {
                if( target > nums[middle] && target <= nums[hi] )
                    lo = middle + 1;
                else
                    hi = middle - 1;
            }
            else
            {
                if( target < nums[middle] )
                    hi = middle - 1;
                else
                    lo = middle + 1;
            }
            cout << lo << hi << endl;
        }
        return -1;
    }
};
