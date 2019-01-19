/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    TreeNode * current;
    vector<TreeNode *> s;
    int state = 0;
    BSTIterator(TreeNode* root) {
        current = root;
    }
    
    /** @return the next smallest number */
    int next() {
        int ret = 0;
        switch(state)
        {
            case 0:
                while(current)
                {
                    s.push_back(current);
                    current = current -> left;
                }
                state = 1;
                ret = s.back()->val;
                break;
            case 1:
                if( s.back() -> right)
                {
                    current = s.back() -> right;
                    s.pop_back();
                    state = 0;
                    return next();
                }
                else
                {
                    s.pop_back();
                    ret = s.back() -> val;
                    current = s.back();
                    state = 1;
                }
                break;
        }
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(state)
        {
            if(s.size() > 1)
                return true;
            else
            {
                if(s.empty())
                    return false;
                else
                    return s.back() -> right;
            }

        }
        else
        {
            return current;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
