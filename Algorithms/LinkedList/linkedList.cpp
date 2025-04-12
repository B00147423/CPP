#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Constructor to initialize data and next
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void addToLinkedList(Node*& head, int data){

   Node* newNode= new Node(data);
   newNode->next = head;
   head = newNode;
};

void printLinkedList(Node* head){

    while (head != NULL){
        cout << head->data << "->";
        head = head->next;
    }

}

int main(){
    Node* head = nullptr;
    addToLinkedList(head, 8);
    addToLinkedList(head, 6);
    addToLinkedList(head, 5);
    addToLinkedList(head, 2);
    addToLinkedList(head, 9);
    printLinkedList(head);
    return 0;
}