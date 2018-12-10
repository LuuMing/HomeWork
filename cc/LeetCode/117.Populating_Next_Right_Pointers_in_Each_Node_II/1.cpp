/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        queue<TreeLinkNode *> q;
        q.push(root);
        TreeLinkNode * back = root;
        while(!q.empty())
        {
            TreeLinkNode * top = q.front();
            if(top -> left)
                q.push(top -> left);
            if( top -> right)
                q.push(top -> right);
            q.pop();
            if(top == back)
            {
                back = q.back();
            }
            else
            {
                top -> next = q.front();
            }
        }
        
    }
};
