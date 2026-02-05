// 86. Partition List 
// https://leetcode.com/problems/partition-list/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
            ListNode* before_head = new ListNode(0);
            ListNode* after_head = new ListNode(0);

            ListNode* before = before_head;
            ListNode* after = after_head;

            while(head != nullptr){
                if (head->val < x) {
                    before->next = head;
                    before = before->next;
                }else{
                    after->next = head;
                    after = after->next;
                }
                head = head->next;
            }
        after->next = nullptr;
        before->next = after_head->next;
        return before_head->next;
    }
};

/*
Input:
head = [1,4,3,2,5,2]
x = 3

Initial:
before_head = 0 -> null
after_head  = 0 -> null
before = before_head
after  = after_head

--------------------------------
Iteration 1:
head = 1

1 < 3 → goes to before list

before->next = 1
before = 1
head = 4

before list: 0 -> 1
after list : 0

--------------------------------
Iteration 2:
head = 4

4 >= 3 → goes to after list

after->next = 4
after = 4
head = 3

before list: 0 -> 1
after list : 0 -> 4

--------------------------------
Iteration 3:
head = 3

3 >= 3 → goes to after list

after->next = 3
after = 3
head = 2

before list: 0 -> 1
after list : 0 -> 4 -> 3

--------------------------------
Iteration 4:
head = 2

2 < 3 → goes to before list

before->next = 2
before = 2
head = 5

before list: 0 -> 1 -> 2
after list : 0 -> 4 -> 3

--------------------------------
Iteration 5:
head = 5

5 >= 3 → goes to after list

after->next = 5
after = 5
head = 2

before list: 0 -> 1 -> 2
after list : 0 -> 4 -> 3 -> 5

--------------------------------
Iteration 6:
head = 2

2 < 3 → goes to before list

before->next = 2
before = 2
head = null

before list: 0 -> 1 -> 2 -> 2
after list : 0 -> 4 -> 3 -> 5

--------------------------------
After loop cleanup:

after->next = null
before->next = after_head->next

Final list (returned):
1 -> 2 -> 2 -> 4 -> 3 -> 5

*/