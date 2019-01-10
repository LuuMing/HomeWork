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
    void dfs(TreeNode * root, int l)
    {
        if(root)
        {
            if(result.size() < l)
            {
                result.push_back({});
            }
            result[l-1].push_back(root -> val);
            dfs(root -> left, l + 1);
            dfs(root -> right, l + 1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 1);
        return result;
    }
};