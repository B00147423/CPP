#include <iostream>
using namespace std;

//Definition for singly-linked list.
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
        
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // edge case: if fast is nullptr now, it means you need to remove head
        if (!fast) {
            return head->next;
        }

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        // here, slow is just before the node to remove
        slow->next = slow->next->next;
        return head;

    }
};