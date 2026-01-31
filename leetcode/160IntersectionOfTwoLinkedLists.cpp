// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    /*

    */

        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while(tempA != tempB){
            if (tempA == nullptr){
                tempA = headB;
            }
            else{
                tempA = tempA->next;
            }
            if (tempB == nullptr){
                tempB = headA;
            }
            else{
                tempB = tempB->next;
            }
                
        }
        return tempA;
    }
};