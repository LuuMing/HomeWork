/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node * > q;
        q.push(root);
        Node * back = root;
        vector<vector<int>> ret;
        vector<int> tmp;
        while(!q.empty())
        {
            Node * top = q.front();
            if(top)
            {
                for(auto & n: top -> children)
                    q.push(n);
                tmp.push_back(top -> val);
            }
            if(top == back && top)
            {
                ret.push_back(tmp);
                tmp.clear();
                back = q.back();
            }
            q.pop();
        }
        return ret;
    }
};
