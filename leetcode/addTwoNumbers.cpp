
 #include <iostream>
 #include <algorithm>

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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            

            ListNode* dummyNode = new ListNode();
            ListNode* cur = dummyNode;

            int carry = 0;
            while(l1 != nullptr || l2 != nullptr || carry != 0){
                int val1 = (l1 != nullptr) ? l1->val : 0;
                int val2 = (l2 != nullptr) ? l2->val : 0;

                int val = val1 + val2 + carry;
                cout << " val : " << val;
                carry = val / 10;
                val = val % 10;
                cur->next = new ListNode(val);

                cur = cur->next;
                l1 = (l1 != nullptr) ? l1->next : nullptr; 
                l2 = (l2 != nullptr) ? l2->next : nullptr;
            }
            ListNode* res = dummyNode->next;
            delete dummyNode;
            return  res;
        }
};

int main(){
    Solution solution;

    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Clean up memory
    while(l1) { ListNode* temp = l1; l1 = l1->next; delete temp; }
    while(l2) { ListNode* temp = l2; l2 = l2->next; delete temp; }
    while(result) { ListNode* temp = result; result = result->next; delete temp; }
}