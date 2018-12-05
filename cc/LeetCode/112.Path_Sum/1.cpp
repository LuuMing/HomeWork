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
    int S = 0;
    bool flag = false;
    bool hasPathSum(TreeNode* root, int sum) {
        if(flag)
            return true;
        if(root)
        {
            S += root -> val;
            if(!root -> left && !root->right)
            {
                if(S == sum)
                    flag = true;
            }
            if(root -> left)
            {
                if(hasPathSum(root -> left, sum))
                    flag = true;
                S -= root -> left ->val;
            }
            if(root -> right && !flag)
            {
                if( hasPathSum(root -> right, sum) )
                    flag = true;
                S -= root -> right ->val;
            }
        }
        return flag;
    }
};
