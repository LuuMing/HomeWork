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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode *> q;
        q.push(root);
        TreeNode * back = root;
        bool flag = false;
        vector<vector<int>> result;
        vector<int> tmp;
        while(!q.empty())
        {
            TreeNode * top = q.front();
            if( top -> left )
            {
                q.push(top->left);
            }
            if ( top -> right)
            {
                q.push(top->right);
            }
            if(flag)
            {
                tmp.insert(tmp.begin(),top->val);
            }
            else
            {
                tmp.push_back(top->val);
            }
            q.pop();
            if( top == back )
            {
                back = q.back();
                result.push_back(tmp);
                tmp.clear();
                flag = !flag;
            }
        }
        return result;
    }
};
