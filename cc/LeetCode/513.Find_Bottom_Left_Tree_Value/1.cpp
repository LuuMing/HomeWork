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
    int deepestlevel = 0;
    int target = 0;
    void dfs(int level, TreeNode* root,bool left)
    {
        if(root)
        {
            if(level > deepestlevel)
            {
                target = root -> val;
                deepestlevel = level;
            }
            else if(level == deepestlevel && left)
                target = root -> val;
             dfs(level + 1, root -> right, false);
            dfs(level + 1, root -> left, true);
           
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(1, root,true);
        return target;
    }
};
