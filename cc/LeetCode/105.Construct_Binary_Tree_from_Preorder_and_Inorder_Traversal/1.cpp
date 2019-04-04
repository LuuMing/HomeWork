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
    vector<int> * pPreorder;
    vector<int> * pInorder;
    TreeNode * build(int pre , int start, int end)
    {
        if(start > end ) return NULL;
        TreeNode * node = new TreeNode(pPreorder->at(pre));
        int idx = start;
        while(pInorder -> at(idx) != pPreorder -> at(pre) ) idx++;
        node -> left = build( pre + 1 ,start ,idx - 1);
        node -> right = build(  pre + (idx - start + 1) ,idx + 1, end);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pPreorder = &preorder;
        pInorder = & inorder;
        TreeNode * root = build(0,0,inorder.size() - 1);
        return root;
    }
};
