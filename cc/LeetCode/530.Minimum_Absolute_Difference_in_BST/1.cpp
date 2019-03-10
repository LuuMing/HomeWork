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
    int minDiff = INT_MAX;
    int pre = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(root)
        {
            getMinimumDifference(root -> left);
            minDiff = min(minDiff,abs( root -> val - pre));
            pre = root -> val;
            getMinimumDifference(root -> right);
        }
        return minDiff;
    }
};
