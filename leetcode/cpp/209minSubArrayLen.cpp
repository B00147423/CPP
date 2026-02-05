#include <vector>
#include <iostream>
class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0;

        int sum = 0;

        int result = INT_MAX;   

        for(int right = 0; right < nums.size(); right++){
            sum+=nums[right];
            while (sum >= target){
                result = std::min(result, right-left+1);
                sum-=nums[left];
                left+=1;
            }
        }
            
        if(result == INT_MAX) return 0;
        return result; 
    }
};

/*
Time Complexity:
O(n) — each element is visited at most twice (once by right, once by left), so total operations are linear.

Space Complexity:
O(1) — only a constant amount of extra space is used (left, sum, result), regardless of input size.

*/