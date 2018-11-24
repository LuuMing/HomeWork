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

    bool cmp(TreeNode * p,TreeNode * q)
    {
        if((!p && !q))
            return true;
        else if( !p || !q)
            return false;
        else
            return p -> val == q -> val && cmp(p -> left,q->left) && cmp(p -> right,q -> right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return cmp(p,q);
    }
};
