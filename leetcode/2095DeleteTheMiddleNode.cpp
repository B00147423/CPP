// 2095. Delete the Middle Node of a Linked List
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}  
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: single node
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // 1) Find size of linked list
        int linkedListSize = 0;
         ListNode* current = head;

        while (current != nullptr) {
            linkedListSize++;
            current = current->next;
        }

        // 2) Find index of node BEFORE the middle
        int nodeBeforeMiddle = (linkedListSize / 2) - 1;

        //2d step traverse list until u find the 
        current = head;
        for (int i = 0; i < nodeBeforeMiddle; i++) {
            current = current->next;
        }
        //current = node before ndoeToDelete
        //nodeToDelete is nodeToDelete hence current->next
        ListNode* nodeToDelete = current->next;
        //skip over nodeToDelete by skipping over nodeToDelete
        current->next = nodeToDelete->next;
        //delete node
        delete nodeToDelete;
        return head;

    }
};

