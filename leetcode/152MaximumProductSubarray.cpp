/*



*/
// 152. Maximum Product Subarray
#include <vector>
class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int maxProd = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] < 0) {
                std::swap(currMax, currMin);
            }
            currMax = std::max(nums[i], currMax * nums[i]);
            currMin = std::min(nums[i], currMin * nums[i]);
            maxProd = std::max(maxProd, currMax);
        }
        return maxProd;
    }
};