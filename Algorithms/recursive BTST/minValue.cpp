#include <iostream>
using namespace std;

class Node { 
public:
    int value;
    Node* right;
    Node* left;

    Node(int value) {
        this->value = value;
        right = nullptr;
        left = nullptr;
    }
}; 

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    int minValue(Node* currentNode) {
        while (currentNode->left != nullptr) {
            currentNode = currentNode->left;		 
        }
        return currentNode->value;
    }
};
