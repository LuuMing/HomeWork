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
bool cmp(TreeNode * left , TreeNode * right)
{
    if(!left && !right)
        return true;
    if(left && right)
    {
        return (left -> val == right -> val) && cmp(left-> left, right -> right) && cmp(left -> right ,right -> left);
    }
    else
        return false;
}
public:
    bool isSymmetric(TreeNode* root) {
       if(!root)
       {
           return true; 
       }
    else
        return cmp(root -> left, root -> right);
}
};
