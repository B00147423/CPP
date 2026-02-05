//23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<int> mergedList;

        for (int row = 0; row < lists.size(); row++) {
            ListNode* curr = lists[row];
            while (curr) {
                mergedList.push_back(curr->val);
                curr = curr->next;
            }
        }
        sort(mergedList.begin(), mergedList.end());

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for(int i = 0; i < mergedList.size(); i++){
            curr->next = new ListNode(mergedList[i]);
            curr = curr->next;
        }
    return dummy->next;
    }
};