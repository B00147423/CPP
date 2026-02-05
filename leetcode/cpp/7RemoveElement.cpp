#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int left = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[left] = nums[i];
                left++;
            }
        }
        return left;
    }
};