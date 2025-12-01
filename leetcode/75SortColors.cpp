#include <vector>
#include <iostream>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int l = 0, i = 0, r = nums.size()-1;
        while( i <= r)
        {
            if(nums[i] == 0)
            {
                std::swap(nums[l], nums[i]);
                l++;
            }
            else if(nums[i] == 2)
            {
                std::swap(nums[i], nums[r]);
                r--;
                i--;
            }
            i++;
        }
    }
};