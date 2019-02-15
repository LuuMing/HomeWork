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
    void find(TreeNode * root ,int & k,int & result)
    {
        if(root)
        {
            find( root -> left, k,result);
            k--;
            if( k == 0 )
            {
                result = root -> val;
                return;
            }
            find( root -> right, k,result);
        }
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int ret = 0;
        find(root,k,ret);
        return ret;
    }
};
