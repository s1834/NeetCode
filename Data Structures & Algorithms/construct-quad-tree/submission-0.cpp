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
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
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
private:
    bool isSame(vector<vector<int>>& grid, int x, int y, int n) {
        int val = grid[x][y];
        for(int i = x; i < x + n; i++) {
            for(int j = y; j < y + n; j++) {
                if(grid[i][j] != val) return false;
            }
        }
        return true;
    }

    Node* build(vector<vector<int>>& grid, int x, int y, int n) {
        if(isSame(grid, x, y, n)) {
            return new Node(grid[x][y], true);
        } else {
            Node* root = new Node(1, false);

            root->topLeft = build(grid, x, y, n /2);
            root->topRight = build(grid, x, y + n /2, n / 2);
            root->bottomLeft = build(grid, x + n / 2, y, n / 2);
            root->bottomRight = build(grid, x + n / 2, y + n / 2, n / 2);

            return root;
        }
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};