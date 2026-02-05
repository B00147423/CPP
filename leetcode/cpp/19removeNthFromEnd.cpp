// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        // 1) Find length
        int length = 0;
        ListNode* curr = head;

        while (curr) {
            length++;
            curr = curr->next;
        }

        int nodeToDelete = length  - n;
        if(nodeToDelete  == 0){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        //[1,2,3,4,5] n = 2 from the end
        curr = head;
        // 3) Walk to node before the one to delete
        for(int i = 0; i < nodeToDelete-1; i++){
            curr = curr->next; // 3
        }

        ListNode* deleteNode = curr->next; // 4
        curr->next = deleteNode->next; //3- >5
        delete deleteNode;
        return head;
    }
};

/*
dry run:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
1) Find length
length = 5
2) nodeToDelete = length - n = 5 - 2 = 3
3) Walk to node before the one to delete
curr = head; // 1
i=0; curr = 2
i=1; curr = 3
4) Delete node
deleteNode = curr->next; // 4
curr->next = deleteNode->next; // 3->5
delete deleteNode;
return head;
*/