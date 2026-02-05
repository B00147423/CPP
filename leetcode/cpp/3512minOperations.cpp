#include <vector>
#include <iostream>


class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        long long sum = 0;
        for (int num : nums)
        {
            sum += num;
            std::cout <<"\nnsum : " << sum;
        } 

        return sum % k;

    }
};

