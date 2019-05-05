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
    unordered_map<int,int> m;
    vector<int> result;
    int max = -1;
    int traversal(TreeNode * root){
        int total = 0;
        int l = 0;
        int r = 0;
        if(root){
            l = traversal( root -> left);
            r = traversal( root -> right);
            total = l + r + root -> val;
            if( ++m[total] > max ){
                max = m[total];
                result.clear();
                result.push_back(total);
            }
            else if(m[total] == max)
                result.push_back(total);
            return l + r + root -> val;
        }
        else
            return 0;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        traversal(root);
        return result;
    }
};
