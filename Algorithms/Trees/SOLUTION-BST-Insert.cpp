#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};


class BinarySearchTree {
    public:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }


        // ---------------------------------------------------
        //  Below is a helper function used by the destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }
 
        bool insert(int value){
            Node* newNode = new Node(value);
            Node* temp = root;
            if (root == nullptr){
                root = newNode;
                return true;
            } 
            while(true){
                if (newNode->value == temp->value) return false;// tests duplicate values
                if (newNode->value < temp->value){ //if newnodes value is less than go left
                    if(temp->left == nullptr){
                        temp->left == newNode;
                        return true;
                    }
                    temp = temp->left;
                }else{
                    if(temp->right == nullptr){//if newnodes value is gerater than go right
                        temp->right == newNode;
                        return true;
                    }
                    temp = temp->right;// makes sure to move onto the enxt node if above if statement not true
                }
            }
        }

    // Check if the BST contains a node with the specified integer value
    bool contains(int value) {
        // If the BST is empty, return false
        if (root == nullptr) return false;
    
        // Create a temp node pointer, initializing it to the root
        Node* temp = root;
    
        // Loop that continues while temp is not null
        while (temp) {
            // If value to search is less than current node's value
            if (value < temp->value) {
                // Move to the left child
                temp = temp->left;
            } else if (value > temp->value) {
                // If value to search is greater than current node's value
                // Move to the right child
                temp = temp->right;
            } else {
                // If value to search equals current node's value
                // Return true
                return true;
            }
        }
        // If value is not found in the tree, return false
        return false;
    }
};


int main() {
        
    BinarySearchTree* myBST = new BinarySearchTree();

    myBST->insert(2);
    myBST->insert(1);
    myBST->insert(3);

    /*
        THE LINES ABOVE CREATE THIS TREE:
                     2
                    / \
                   1   3
    */
        
                  

    // ROOT MUST BE PUBLIC FOR THESE LINES TO WORK
    cout << "Root: " << myBST->root->value;
    cout << "\n\nRoot->Left: " << myBST->root->left->value;
    cout << "\n\nRoot->Right: " << myBST->root->right->value;


    /*
        EXPECTED OUTPUT:
        ----------------
        Root: 2

        Root->Left: 1

        Root->Right: 3

    */

}
