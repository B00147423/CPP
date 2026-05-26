//Leetcode 268. Missing Number
// Link: https://leetcode.com/problems/missing-number/description/

#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        
        for (int i = 0; i <= nums.size(); i++) {
            if (find(nums.begin(), nums.end(), i) == nums.end()) {
                res = i;
                return res;
            }
        }

        return -1;

    }
};