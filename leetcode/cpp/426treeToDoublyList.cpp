
#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


class Solution {
    Node* curr = nullptr;
    Node* prev = nullptr;


public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;

        dfsInorder(root);

        // close the circular link
        curr->left = prev;
        prev->right = curr;

        return curr;
    }
private:
    void dfsInorder(Node* headNode) {
        if (!headNode) return;

        dfsInorder(headNode->left);

        if (prev) {
            prev->right = headNode;
            headNode->left = prev;
        } else {
            curr = headNode;
        }

        prev = headNode;
        dfsInorder(headNode->right);
    }

};