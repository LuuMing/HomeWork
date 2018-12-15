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
    int tmp = 0;
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        if(root)
        {
            tmp = tmp * 10 + root -> val;
            if(!root -> left && ! root -> right)
            {
                sum += tmp;
            }
            else
            {
                if( root -> left)
                {
                    sumNumbers(root -> left);
                    tmp = (tmp - root -> left -> val) / 10;
                }
                if( root -> right)
                {   
                    sumNumbers(root ->  right);
                    tmp = (tmp - root -> right -> val) / 10;
                }
            }
        }
        return sum;
    }
};
