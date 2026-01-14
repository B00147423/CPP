
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        /*
            is the list sorted?
            can there be a lit that is not sorted?
            does list only contain intergers? 

        */
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // 1. Find length and tail
        int listLength = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            listLength++;
        }

        // 2. Reduce k
        k = k % listLength;
        if (k == 0)
            return head;

        // 3. Make list circular
        tail->next = head;

        // 4. Find new tail
        int stepsToNewTail = listLength - k;
        ListNode* newTail = head;

        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};