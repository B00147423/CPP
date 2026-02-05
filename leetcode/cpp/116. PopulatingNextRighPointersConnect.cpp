#include <cstddef>
#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {

        if (root == nullptr) {
            return root;
        }


        Node* leftmost = root;
        // Once we reach the final level, we are done
        while (leftmost->left != nullptr) {
            // Iterate the "linked list" starting from the head
            // node and using the next pointers, establish the
            // corresponding links for the next level
            Node* head = leftmost;
            while (head != nullptr) {
                // CONNECTION 1
                head->left->next = head->right;
                // CONNECTION 2
                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }
                // Progress along the list (nodes on the current level)
                head = head->next;
            }
            // Move onto the next level
            leftmost = leftmost->left;
        }
        return root;
    }
};