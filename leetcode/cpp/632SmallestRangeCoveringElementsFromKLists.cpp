
//632. Smallest Range Covering Elements from K Lists
// Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Priority queue to store (value, list index, element index)
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        int maxVal = INT_MIN, rangeStart = 0, rangeEnd = INT_MAX;

        // Insert the first element from each list into the min-heap
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        // Continue until we can't proceed further
        while (pq.size() == nums.size()) {
            auto [minVal, indices] = pq.top();
            pq.pop();
            int row = indices.first, col = indices.second;

            // Update the smallest range
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // If possible, add the next element from the same row to the heap
            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col + 1];
                pq.push({nextVal, {row, col + 1}});
                maxVal = max(maxVal, nextVal);
            }
        }

        return {rangeStart, rangeEnd};
    }
};
  /*
        find the smallest range that includes at least one number from each of the k lits

nums = [
        [4,10,15,24,26],
        [0,9,12,20],
        [5,18,22,30]
        ]




        */