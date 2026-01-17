#include <vector>
#include <unordered_map>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;
        vector<int> result;

        // Process nums2
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && nums2[i] > st.top()) {
                nextGreater[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        // Remaining elements have no next greater
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // Build result for nums1
        for (int x : nums1) {
            result.push_back(nextGreater[x]);
        }

        return result;
    }
};
int main() {
    Solution s;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = s.nextGreaterElement(nums1, nums2);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}