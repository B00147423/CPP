// 100. Same Tree
// https://leetcode.com/problems/same-tree/
#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        /*
        if p and q arte the same node val and had elft and right 

        if p and q.val  
        */

        // Case 1: both are null
        if (p == nullptr && q == nullptr)return true;


        // Case 2: one is null
        if (p == nullptr || q == nullptr)return false;

        if(p->val != q->val){
            return false;
        }
        
        return isSameTree(p->left, q->left) && 
                isSameTree(p->right, q->right);
    }
};