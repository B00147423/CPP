// 236. Lowest Common Ancestor of a Binary Tree
 //Definition for a binary tree node.
#include <cstddef>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }

private:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        // If the current node is either p or q, return it
        if (root == p || root == q) {
            return root;
        }
        // Recur on the left and right subtrees
        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);

        // If both left and right are non-null, root is the LCA
        if (left != nullptr && right != nullptr) {
            return root;
        }

        if(left !=  nullptr){
            return left;
        }else{
            return right;
        }
    }
};
