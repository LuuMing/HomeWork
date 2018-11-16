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
    TreeNode * insert(TreeNode * root, int data)
    {
        if(!root)
            root = new TreeNode(data);
        else
        {
            if(root -> val < data)
            {
                root -> right = insert(root -> right,data);
            }
            else
            {
                root -> left = insert(root -> left, data);
            }
        }
        return root;
    }
    TreeNode * r;
    void post(TreeNode * root, int L, int R)
    {
        if(root)
        {
            if(root -> val >= L && root -> val <= R)
            {
                r = insert(r,root->val);
            }
            post( root->left, L, R);
            post( root->right, L, R);
        }
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        post(root,L,R);
        return r;
    }
};
