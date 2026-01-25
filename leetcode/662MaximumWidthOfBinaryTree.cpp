// 662. Maximum Width of Binary Tree
// https://leetcode.com/problems/maximum-width-of-binary-tree/

#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});



        while (!q.empty()) {
            int size = q.size();
            long long first = q.front().second;
            long long last = first;

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();

                idx -= first;
                cout << "\nidx =" << idx ;
                last = idx;
    

                if (node->left)  q.push({node->left,  2 * idx});
                if (node->right) q.push({node->right, 2 * idx + 1});
            }

            maxWidth = max(maxWidth, last + 1);
        }
        return (int)maxWidth;
    }
};
/*
itiration 1
    q = { (1,0) }
    size = 1
    first = 0
    last = 0
loop i=0:
    auto = node 1, idx 0
    pop → q = {}
    idx -= first → 0-0 = 0
    last = idx = 0
    left = {3, 2*0 = 0} → push
    right = {2, 2*0+1 = 1} → push
    q = { (3,0), (2,1) }
    maxWidth = last+1 = 0+1 = 1

itiration 2
    q = { (3,0), (2,1) }
    size = 2
    first = 0
    last = 0

loop i=0:
    auto = node 3, idx 0
    pop → q = { (2,1) }
    idx -= first → 0-0 = 0
    last = 0
    left = {5, 2*0 = 0} → push
    right = {3, 2*0+1 = 1} → push
    q = { (2,1), (5,0), (3,1) }

loop i=1:
    auto = node 2, idx 1
    pop → q = { (5,0), (3,1) }
    idx -= first → 1-0 = 1
    last = 1
    left = null → no push
    right = {9, 2*1+1 = 3} → push
    q = { (5,0), (3,1), (9,3) }
    maxWidth = max(prev, last+1) = max(1, 1+1=2) = 2

itiration 3
    q = { (5,0), (3,1), (9,3) }
    size = 3
    first = 0
    last = 0

loop i=0:
    auto = node 5, idx 0
    pop → q = { (3,1), (9,3) }
    idx -= first → 0-0=0
    last = 0
    left = null, right = null

loop i=1:
    auto = node 3, idx 1
    pop → q = { (9,3) }
    idx -= first → 1-0=1
    last = 1
    left = null, right = null
    loop i=2:
    auto = node 9, idx 3
    pop → q = {}
    idx -= first → 3-0=3
    last = 3
    left = null, right = null
    maxWidth = max(prev, last+1) = max(2, 3+1=4) = 4
*/