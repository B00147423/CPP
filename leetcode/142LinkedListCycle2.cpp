// LeetCode Problem 142: Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/
#include <cstddef>
 struct ListNode
 {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}

};
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;
        //detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;

                //find cycle start pooint
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

/*
Linked List:
3 → 2 → 0 → -4
    ↑        ↓
    └────────┘
makefile
Copy code
PHASE 1: DETECT CYCLE

Start:
slow = 3
fast = 3

Step 1:
slow = 2
fast = 0

Step 2:
slow = 0
fast = 2

Step 3:
slow = -4
fast = -4   <-- meet
makefile
Copy code
PHASE 2: FIND CYCLE START

Reset:
slow = 3
fast = -4

Step 1:
slow = 2
fast = 2   <-- meet (cycle start)
sql
Copy code
RETURN NODE WITH VALUE = 2


*/