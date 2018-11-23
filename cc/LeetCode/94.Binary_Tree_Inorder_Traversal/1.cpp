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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode * curr = root;
        vector<int> result;
        while(!s.empty() || curr)
        {
            while(curr)
            {
                s.push(curr);
                curr = curr -> left;
            }
            curr = s.top(); 
            result.push_back(curr->val);
            curr = curr->right;
            s.pop();
        }
        return result;
    }
};
