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
    void bfs(TreeNode * root, int level,vector<vector<int>> & ret){
        if(root){
            if(level == ret.size()){
                ret.push_back({});
            }
            ret[level].push_back(root -> val);
            bfs(root -> left, level + 1, ret);
            bfs(root -> right, level + 1, ret);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>  ret;
        bfs( root, 0 , ret);
        return vector<vector<int>>(ret.rbegin(),ret.rend());
    }
};
