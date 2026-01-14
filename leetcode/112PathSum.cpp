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
    bool hasPathSum(TreeNode* root, int targetSum) {
        /*
            edge case return nullptr if the roto is emtpy;

            We first check if the current root exists. If it’s null, we return false because there’s no path.

            We subtract the current node’s value from targetSum. This helps us track how much of the original sum is left as we go down the path.

            If we reach a leaf node (meaning both root->left and root->right are null), we check:

            If targetSum == 0, that means the values from the root to this leaf add up exactly to the original target — so we return true.
            Otherwise, this path doesn’t work, so we return false.
            If we’re not at a leaf, we recursively check the left subtree or the right subtree with the updated targetSum.

            As soon as any path (left or right) returns true, the whole function returns true. If neither does, it returns false.


        */

        if(!root) return false;

        targetSum -= root->val;
        if(!root->left && !root->right) //reach the end of left and righ
            if (targetSum == 0) {
                return true;
            } else {
                return false;
            }
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);

    }
};