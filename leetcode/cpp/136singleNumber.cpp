#include <vector>
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {


        int result = 0;
        for (int n : nums)
        {     
            result ^= n;
        }
        return result;
    }
};