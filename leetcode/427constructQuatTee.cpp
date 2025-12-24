#include <vector>
using namespace std;

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

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return solveDFS(grid, 0, 0, grid.size());
    }
public:
    Node* solveDFS(vector<vector<int>>& grid, int r, int c, int length){
            if (length == 1) {
                return new Node(grid[r][c], true);
            }

            Node* topLeft     = solveDFS(grid, r, c, length / 2);
            Node* topRight    = solveDFS(grid, r, c + length / 2, length / 2);
            Node* bottomLeft  = solveDFS(grid, r + length / 2, c, length / 2);
            Node* bottomRight = solveDFS(grid, r + length / 2, c + length / 2, length / 2);


            if( topLeft->isLeaf && topRight->isLeaf && 
                bottomLeft->isLeaf && bottomRight->isLeaf &&
                topLeft->val == topRight->val &&
                topLeft->val == bottomLeft->val &&
                topLeft->val == bottomRight->val
            ){
                return new Node(topLeft->val, true);
            }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};