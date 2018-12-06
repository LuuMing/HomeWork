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
    vector<vector<int>> result;
    vector<int> tmp;
    int S = 0;
    void dfs(TreeNode * root, int sum)
    {
        if(root)
        {
            tmp.push_back(root -> val);
            S += root -> val;
            if(!root -> left && !root -> right&& S == sum )
            {
                result.push_back(tmp);
                return;
            }
            if(root -> left)
            {
                dfs(root -> left, sum);
                tmp.pop_back();
                S -= root -> left -> val;
            }
            if(root -> right)
            {
                dfs(root -> right, sum);
                tmp.pop_back();
                S -= root -> right -> val;
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root,sum);
        return result;
    }
};
