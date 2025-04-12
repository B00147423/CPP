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

	Node* rInsert(Node* currentNode, int value){
		if(currentNode == nullptr) return new Node(value);
		if(value < currentNode->value){
			currentNode->left = rInsert(currentNode->left, value);
		}else if(value > currentNode->value){
			currentNode->right = rInsert(currentNode->right, value);
		}
		return currentNode;
	}

	void rInsert(int value){
		if(root == nullptr) root = new Node(value);
			rInsert(root, value);
	}
};



