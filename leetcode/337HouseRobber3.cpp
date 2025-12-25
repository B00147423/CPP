#include <algorithm>
#include <utility>

/**
 * Definition for a binary tree node.
 */
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
    int rob(TreeNode* root) {
        if (!root) return 0;

        auto res = dfs(root);
        return std::max(res.first, res.second);

    }

private:
    std::pair<int,int> dfs(TreeNode* node) {   // <rob, skip>
        // will fill logic afterwards
        if (!node) return {0,0};  
        
        auto left  = dfs(node->left); 
        auto right = dfs(node->right);          
        int rob  = node->val + left.second + right.second;
        int skip = std::max(left.first, left.second) + std::max(right.first, right.second);
        return {rob, skip};
    }


};