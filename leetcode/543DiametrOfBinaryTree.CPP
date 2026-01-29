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