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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root)
        {
            S += root -> val;
            if(!root -> left && !root->right)
            {
                if(S == sum)
                return true;
                else
                    return false;
            }
            bool r_l = false, r_r = false;
            if(root -> left)
            {
                r_l = hasPathSum(root -> left, sum);
                S -= root -> left ->val;
            }
            if(root -> right)
            {
                r_r = hasPathSum(root -> right, sum);
                S -= root -> right ->val;
            }
            return r_l || r_r;
        }
        else
        {
            return false;
        }
    }
};
