
#include <iostream>
using namespace std;
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        // Find first index from left where order breaks
        while (left < n - 1 && nums[left] <= nums[left + 1]) {
            left++;
        }
        if (left == n - 1) {
            return 0; // Already sorted
        }

        // Find first index from right where order breaks
        while (right > 0 && nums[right] >= nums[right - 1]) {
            right--;
        }

        // Find min and max in the unsorted window [left, right]
        int sub_min = *min_element(nums.begin() + left, nums.begin() + right + 1);
        int sub_max = *max_element(nums.begin() + left, nums.begin() + right + 1);

        // Expand window to the left
        while (left > 0 && nums[left - 1] > sub_min) {
            left--;
        }

        // Expand window to the right
        while (right < n - 1 && nums[right + 1] < sub_max) {
            right++;
        }

        return right - left + 1;
    }
};