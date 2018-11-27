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
    long  N = LONG_MIN;
    bool flag = true;
public:
    bool isValidBST(TreeNode* root) {
       if(!flag) return false;
       if(root)
       {
            isValidBST(root->left);
            if(root -> val > N )
            {
                 N = root -> val;
            }
            else
            {
                 flag = false;
            }
           isValidBST(root->right);
        }
        return flag;
}
};
