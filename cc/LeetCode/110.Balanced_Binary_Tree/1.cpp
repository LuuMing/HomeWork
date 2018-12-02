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
    int getHigh(TreeNode * root)
    {
        if(! root)
            return 0;
        else
            return max(getHigh(root -> left), getHigh(root -> right)) + 1;
    } 

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        else if(!root -> left && root -> right)
        {
            return getHigh(root -> right ) < 2;
        }
        else if(!root -> right && root -> left)
        {
            return getHigh(root -> left) < 2;
        }
        return isBalanced(root->left) && isBalanced(root -> right)&& (abs(getHigh(root -> left) - getHigh(root -> right)) < 2);
        
    }
};
