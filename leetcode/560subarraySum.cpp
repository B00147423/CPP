
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefixSums;
        int curSum = 0;
        int result = 0;
        
        prefixSums[0] = 1;

            for(int num : nums){
                curSum += num;
                int difference = curSum - k;
            result += prefixSums[difference];

            prefixSums[curSum]++;
            }
            return result;
    }
};