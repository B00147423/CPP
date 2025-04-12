#include <vector>
#include <unordered_map>

#include <iostream>
#include <vector>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map; // To store the value and its index
        std::vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (num_map.find(complement) != num_map.end()) {
                // If found, return the indices
                result.push_back(num_map[complement]);
                result.push_back(i);
                return result;
            }
            
            // Otherwise, add the current number and its index to the map
            num_map[nums[i]] = i;
        }

        return result; // In case there is no solution, though the problem states there will always be one
    }
};



int main() {
    Solution solution;
    
    // Test Case 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = solution.twoSum(nums1, target1);
    std::cout << "Test 1 Output: [" << result1[0] << ", " << result1[1] << "]" << std::endl;
    std::cout << "Expected: [0, 1]" << std::endl;
    
    // Test Case 2
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = solution.twoSum(nums2, target2);
    std::cout << "Test 2 Output: [" << result2[0] << ", " << result2[1] << "]" << std::endl;
    std::cout << "Expected: [1, 2]" << std::endl;
    
    // Test Case 3
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = solution.twoSum(nums3, target3);
    std::cout << "Test 3 Output: [" << result3[0] << ", " << result3[1] << "]" << std::endl;
    std::cout << "Expected: [0, 1]" << std::endl;
    
    return 0;
}
