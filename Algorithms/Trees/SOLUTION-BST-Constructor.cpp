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
            return true;
        }
        
};



int main() {
        
    BinarySearchTree* myBST = new BinarySearchTree();

    // ROOT MUST BE PUBLIC FOR THIS LINE TO WORK:
    cout << "Root: " << myBST->root;

    /*
        EXPECTED OUTPUT:
        ----------------
        Root: 0x0

    */

}

