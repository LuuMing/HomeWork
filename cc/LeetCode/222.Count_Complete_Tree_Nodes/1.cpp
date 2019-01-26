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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode * > q;
        q.push(root);
        int cnt = 1;
        while( !q.empty() )
        {
            TreeNode * top = q.front();
            if(!top -> left )
                return 2 * cnt -1;
            else if( !top -> right)
                return 2 * cnt;
            else
            {
                q.push(top -> left);
                q.push( top -> right );
            }
            q.pop();
            cnt++;
        }
        return cnt;
    }
};
