#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast n nodes ahead
        for (int i = 0; i < n; ++i) {
            if (fast == nullptr) {
                return nullptr; // n is greater than the length of the list
            }
            fast = fast->next;
        }

        // If fast is null, n is the length of the list and we need to remove the head
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head; // Free the memory of the old head
            return newHead;
        }

        // Move both pointers until fast reaches the end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Adjust pointers to remove the nth node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Free the memory of the deleted node

        return head;
    }
};