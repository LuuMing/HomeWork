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
    int sum = 0;
    void sumWithMark(TreeNode * root, bool left)
    {
        if(root)
        {
            if( !root-> left && !root-> right && left )
            {
                sum += root -> val;
            }
            else
            {
                sumWithMark(root->left, true);
                sumWithMark(root->right, false);
            }
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root)
        {
            sumWithMark(root -> left, true);
            sumWithMark(root -> right, false);
        }
        return sum;
    }
};
