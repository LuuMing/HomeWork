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
    vector<string> result;
    void visit(TreeNode * root, string str)
    {
        if(root)
        {
            str += to_string(root -> val);
            if(root -> left || root -> right)
            {
                str += "->";
                visit(root -> left,str);
                visit(root -> right,str);
            }
            else
            {
                result.push_back(str);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        visit(root,"");
        return result;
    }
};
