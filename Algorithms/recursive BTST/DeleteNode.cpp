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

	Node* deleteNode(Node* currentNode, int value){
		
		if(value < currentNode->value){
			currentNode->left = deleteNode(currentNode->left, value);
		}else{
			if(currentNode->left == nullptr && currentNode->right == nullptr){
			delete(currentNode);
			return nullptr;
			}else if(currentNode->left == nullptr){
				Node* temp = currentNode->right;
				delete(currentNode);
				return temp;
		}else if(currentNode->left == nullptr){
				Node* temp = currentNode->left;
				delete(currentNode);
				return temp;
		}else{
			int subTreeMin = minValue(currentNode->right);
			currentNode->value = subTreeMin;
			currentNode->right = deleteNode(currentNode->right, subTreeMin);
		}
	    }
        return currentNode;
    };

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

// Function to print all nodes in the tree
    void printTree(Node* node) {
        if (node == nullptr) {
            return;
        }

        // Print the current node's value
        cout << node->value << " ";

        // Recursively print the left and right subtrees
        printTree(node->left);
        printTree(node->right);
    }

    // Function to start printing from the root
    void printTree() {
        printTree(root);
        cout << endl; // Newline for better readability
    }
};


int main() {
    BinaryTree tree;

    // Manually creating the tree for demonstration
    tree.root = new Node(50);
    tree.root->left = new Node(30);
    tree.root->left->left = new Node(20);
    tree.root->left->right = new Node(40);
    tree.root->right = new Node(70);
    tree.root->right->left = new Node(60);
    tree.root->right->right = new Node(80);

    cout << "Original tree: ";
    tree.printTree();

    // Delete node with value 20
    tree.deleteNode(20);
    cout << "Tree after deleting 20: ";
    tree.printTree();

    // Delete node with value 30
    tree.deleteNode(30);
    cout << "Tree after deleting 30: ";
    tree.printTree();

    // Delete node with value 50
    tree.deleteNode(50);
    cout << "Tree after deleting 50: ";
    tree.printTree();

    return 0;
}
