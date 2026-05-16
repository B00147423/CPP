// 3912. Valid Elements in an Array
// link: https://leetcode.com/problems/valid-elements-in-an-array/description/
#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<int> findValidElements(std::vector<int>& nums) {
        std::vector<int> result;
        int n = nums.size();

        if (n == 1) {
            return {nums[0]};
        }

        std::vector<int> leftMax(n);
        std::       vector<int> rightMax(n);

        leftMax[0] = -1;
        rightMax[n - 1] = -1;

        for (int i = 1; i < n; i++) {
            leftMax[i] = std::max(leftMax[i - 1], nums[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = std::max(rightMax[i + 1], nums[i + 1]);
            std::cout << "i=" << i
                << " rightMax[" << i << "] = max(rightMax[" << i+1 << "], nums[" << i+1 << "]) = "
                << rightMax[i] << std::endl;
        }

        result.push_back(nums[0]);

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > leftMax[i] || nums[i] > rightMax[i]) {
                result.push_back(nums[i]);
            }
        }

        result.push_back(nums[n - 1]);
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 3, 2, 4, 5};
    std::vector<int> validElements = solution.findValidElements(nums);

    std::cout << "Valid elements: ";
    for (int num : validElements) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}