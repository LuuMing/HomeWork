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
    map<int,int> m;
    void dfs(TreeNode * root,int l)
    {
        if(root)
        {
            if(!m.count(l))
                m[l] = root -> val;
            dfs(root -> right,l + 1);
            dfs(root -> left, l + 1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        dfs(root,0);
        for(auto & i: m)
            v.push_back(i.second);
        return v;
    }
};
