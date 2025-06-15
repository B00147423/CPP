#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// Tree node definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    unordered_map<int, vector<int>> graph;

    int amountOfTime(TreeNode* root, int start) {
        buildGraphIteratively(root);

        queue<int> q;
        q.push(start);
        unordered_set<int> visited;
        visited.insert(start);

        int minutesPassed = -1;

        while (!q.empty()) {
            ++minutesPassed;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                int currentNode = q.front();
                q.pop();

                for (int neighbor : graph[currentNode]) {
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }

        return minutesPassed;
    }

private:
    void buildGraphIteratively(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            TreeNode* currentNode = nodeQueue.front();
            nodeQueue.pop();

            if (currentNode->left) {
                graph[currentNode->val].push_back(currentNode->left->val);
                graph[currentNode->left->val].push_back(currentNode->val);
                nodeQueue.push(currentNode->left);
            }

            if (currentNode->right) {
                graph[currentNode->val].push_back(currentNode->right->val);
                graph[currentNode->right->val].push_back(currentNode->val);
                nodeQueue.push(currentNode->right);
            }
        }
    }
};

int main() {
    // Example binary tree:
    //         1
    //        / \
    //       5   3
    //          / \
    //         10  6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);

    int start = 3;

    Solution solution;
    int result = solution.amountOfTime(root, start);

    cout << "Minutes to burn the entire tree: " << result << endl;

    // Clean up memory (optional in small test code)
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
