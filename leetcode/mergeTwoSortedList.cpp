#include <iostream>
#include <unordered_map>
using namespace std;
#include <stack>

  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Check if either list is empty
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        // Initialize the head of the merged list
        ListNode* head;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        // Use a pointer to keep track of the last node in the merged list
        ListNode* current = head;
        // Merge remaining nodes in sorted order
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        // Attach remaining nodes of the non-exhausted list
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }
            // Return the head of the merged list
        return head;
    }
};