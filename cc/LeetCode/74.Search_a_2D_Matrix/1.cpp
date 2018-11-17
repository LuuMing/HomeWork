class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, hi = matrix.size();
        if(matrix.empty())
            return false;
        while(low < hi - 1)
        {
            int mid = (low + hi) / 2;
            if(matrix[mid][0] > target)
                hi = mid;
            else if(matrix[mid][0] < target)
                low = mid;
            else
                return true;
        }
        int row = low;
        if(matrix[row].empty() )
            return false;
        if(hi < matrix.size() && (matrix[hi][0] == target))
            return true;
        low = 0, hi = matrix[row].size() - 1;
        while(low < hi)
        {
            int mid = (low + hi) / 2;
            if(matrix[row][mid] > target)
            {
                hi = mid - 1;
            }
            else if(matrix[row][mid] < target)
            {
                low = mid + 1;
            }
            else
                return true;
        }
        if(matrix[row][low] == target)
            return true;
        return false;
    }
};
