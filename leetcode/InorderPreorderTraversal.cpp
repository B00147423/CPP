#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
 
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      unordered_map<int, int> inorderIndex;
        for(int i = 0; i < inorder.size(); i++){
            inorderIndex[inorder[i]] = i;
        }
        int preIndex = 0;  
        return build(preorder, inorder, inorderIndex, preIndex, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    unordered_map<int, int>& inorderIndex,
                    int& preIndex, int left, int right) {
        if (left > right) return nullptr;

        // Root value = current preorder element
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Split inorder into left/right subtrees
        int inIndex = inorderIndex[rootVal];

        // Build left and right recursively
        root->left = build(preorder, inorder, inorderIndex, preIndex, left, inIndex - 1);
        root->right = build(preorder, inorder, inorderIndex, preIndex, inIndex + 1, right);

        return root;
    }
};