#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
// Definition for a binary tree node.
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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = nullptr;

        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start) {
                startNode = node;
            }

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        queue<TreeNode*> queue;
        unordered_set<TreeNode*> visited;

        queue.push(startNode);
        visited.insert(startNode);

        int minutes = -1;


        while (!queue.empty()) {
            int size = queue.size();   // one full layer

            for (int i = 0; i < size; i++) {
                TreeNode* node = queue.front();
                queue.pop();

                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    queue.push(node->left);
                }

                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    queue.push(node->right);
                }

                if (parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    queue.push(parent[node]);
                }
            }

            minutes++;
        }
        return minutes++; // temporary
    }
};
