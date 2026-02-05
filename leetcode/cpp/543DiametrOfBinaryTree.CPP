// LeetCode Problem 543: Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {

        int maxDiameterLength = 0;
        dfs(root, maxDiameterLength);
        return maxDiameterLength;
    }
private:
    int dfs(TreeNode* node, int& maxDiameterLength){
        if(!node) return 0;
        int leftSide = dfs(node->left, maxDiameterLength);
        int rightSide= dfs(node->right, maxDiameterLength);

        maxDiameterLength = max(maxDiameterLength, leftSide + rightSide);
        return 1+max(leftSide,rightSide);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree

/*
This solution uses a depth-first search (DFS) approach to calculate the diameter of a binary tree.
dry run:
        1
       / \
      2   3
     / \
    4   5
- Start at root (1):
    - DFS left (2):
        - DFS left (4):
            - DFS left (null): return 0
            - DFS right (null): return 0
            - maxDiameterLength = max(0, 0 + 0) = 0
            - return 1 + max(0, 0) = 1
        - DFS right (5):
            - DFS left (null): return 0
            - DFS right (null): return 0
            - maxDiameterLength = max(0, 0 + 0) = 0
            - return 1 + max(0, 0) = 1
        - maxDiameterLength = max(0, 1 + 1) = 2
        - return 1 + max(1, 1) = 2
    - DFS right (3):
        - DFS left (null): return 0
        - DFS right (null): return 0
        - maxDiameterLength = max(2, 0 + 0) = 2
        - return 1 + max(0, 0) = 1
- maxDiameterLength = max(2, 2 + 1) = 3
- return maxDiameterLength = 3
*/