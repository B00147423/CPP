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
// Time Complexity: O(m + n) where m and n are the lengths of the two linked lists
// Space Complexity: O(1)

/*
dry run: 
List A:     4 -> 1 \
                   -> 8 -> 4 -> 5
List B: 5 -> 6 ->1 /

start:
A: 4        B: 5

move:
A: 1        B: 6
A: 8        B: 1
A: 4        B: 8
A: 5        B: 4
A: null     B: 5

reset:
A: 5        B: null

move:
A: 6        B: 4
A: 1        B: 1
A: 8        B: 8   ← SAME NODE


*/