class Solution {
public:

    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int result = 0;
        while( i < j )
        {
            int tmp = (j - i) * min(height[j] , height[i]);
            result = (tmp > result)?tmp : result;
            if(height[i] < height[j])
                    i++;
            else
                    j--;
        }
        return result;
    }
};
