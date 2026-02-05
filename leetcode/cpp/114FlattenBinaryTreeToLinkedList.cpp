// 114. Flatten Binary Tree to Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

#include <vector>
#include <iostream>
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
    void flatten(TreeNode* root) {
        if(!root)return;
        //// processes nodes: 2, 3, 4
        flatten(root->left);   
        // processes nodes: 5, 6
        flatten(root->right);  

        //1, 5, 6
        TreeNode* originalRight = root->right;

        //1->left = 2
        //1->right = 2
        root->right = root->left;   //            
        root->left = nullptr;  // clear left

        TreeNode* current = root;//1

        while(current->right != nullptr){
            current = current->right;
        }
        current->right = originalRight;
    }
};


/*
dry run:
Start (after recursion)
      1
     / \
    2   5
     \   \
      3   6
       \
        4

Line 1
TreeNode* originalRight = root->right;


Save 5.

originalRight -> 5

      1
     / \
    2   5
     \   \
      3   6
       \
        4

Line 2
root->right = root->left;


Change only 1->right.

      1
     /
    2
     \
      3
       \
        4


(Also: 1->right now points to the same 2.
No new nodes. Same chain.)

Line 3
root->left = nullptr;


Remove left pointer.

1
 \
  2
   \
    3
     \
      4


(5 -> 6 is still saved in originalRight.)

Line 4
TreeNode* current = root;

current = 1

1 -> 2 -> 3 -> 4

While loop
while (current->right != nullptr)
    current = current->right;


Moves:

current: 1 -> 2 -> 3 -> 4


Stops at 4.

Final line
current->right = originalRight;


Attach saved right side.

1 -> 2 -> 3 -> 4 -> 5 -> 6

*/
