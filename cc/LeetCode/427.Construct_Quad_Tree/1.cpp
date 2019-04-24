/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node * build(int x_s, int x_e, int y_s, int y_e ,vector<vector<int>>& grid)
    {
        Node * ret = NULL;
        if(x_s == x_e && y_s == y_e){
            ret =  new Node( grid[x_s][y_s] == 1,true, NULL, NULL, NULL, NULL);
        }
        else{
            bool flag = true;
            for(int i = x_s; i <= x_e && flag; i++){
                for(int j = y_s; j <= y_e ; j++){
                    if(grid[x_s][y_s] != grid[i][j]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                ret = new Node(grid[x_s][y_s] == 1, true, NULL, NULL, NULL, NULL);
            }
            else{
                ret = new Node(true, false, NULL, NULL, NULL, NULL);
                ret -> topLeft = build(x_s,(x_s + x_e) / 2, y_s, (y_s + y_e) / 2,grid);
                ret -> topRight = build(x_s,(x_s + x_e) / 2, (y_s + y_e) / 2 + 1, y_e ,grid);
                ret -> bottomLeft = build((x_s + x_e) / 2 + 1,x_e , y_s, (y_s + y_e) / 2,grid);
                ret -> bottomRight = build((x_s + x_e) / 2 + 1, x_e , (y_s + y_e) / 2 +1, y_e, grid);
            }
        }
        return ret;
    }
    Node* construct(vector<vector<int>>& grid) {
        Node * root = build(0, grid.size() - 1, 0, grid.size() - 1,grid);
        return root;
    }
};
