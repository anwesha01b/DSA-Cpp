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
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
    Node* build(vector<vector<int>>& grid, int row, int col, int size) {
        int val = grid[row][col];
        bool uniform = true;
        for (int i = row; i < row + size && uniform; i++) {
            for (int j = col; j < col + size && uniform; j++) {
                if (grid[i][j] != val) {
                    uniform = false;
                }
            }
        }
        if (uniform) {
            return new Node(val == 1, true);
        }
        int half = size / 2;
        Node* topLeft = build(grid, row, col, half);
        Node* topRight = build(grid, row, col + half, half);
        Node* bottomLeft = build(grid, row + half, col, half);
        Node* bottomRight = build(grid, row + half, col + half, half);
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};