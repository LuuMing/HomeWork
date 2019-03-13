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
    int pre = 0;
    TreeNode* convertBST(TreeNode* root) {
        if( root )
        {
            convertBST(root -> right);
            root -> val += pre;
            pre = root -> val;
            convertBST(root -> left);
        }
        return root;
    }
};
