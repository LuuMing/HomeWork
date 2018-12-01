/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode * build(int left, int right, vector<int>& nums)
    {
        if(left > right)
        {
            return NULL;
        }
        int mid = (left + right) / 2; 
        TreeNode * root = new TreeNode(nums[mid]);
        root -> left = build(left,mid - 1,nums);
        root -> right = build(mid + 1, right,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(0,nums.size() - 1,nums);
    }
};
