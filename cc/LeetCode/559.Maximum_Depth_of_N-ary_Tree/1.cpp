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
    int maxDepth(Node* root) {
        if(!root) return 0;
        queue<Node *> q;
        q.push(root);
        Node * back = root;
        int depth = 0;
        while( !q.empty() )
        {
            for(auto & n : q.front()->children)
                q.push(n);
            if(q.front() == back)
            {
                back = q.back();
                depth++;
            }
            q.pop();
        }
        return depth;
    }
};
