//238. Product of Array Except Self
//https://leetcode.com/problems/product-of-array-except-self/
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> result(n, 1);

        //firstPASS leftside product
        int leftProduct = 1;

        for(int i = 0; i < n; i++){
            result[i] *= leftProduct;
            leftProduct*= nums[i];
        }
        //secodn pass rightside product
        int rightProduct = 1;
        for(int i = n-1; i >=0; i--){
            result[i] *=rightProduct;
            rightProduct *=nums[i];
        }
        return result;
    }
};

/*
dry run:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Explanation:
- Initialize result array with size n and all elements as 1: result = [1, 1, 1, 1]
- First Pass (Left Side Product):
  - i = 0: leftProduct = 1, result[0] = 1 * 1 = 1, leftProduct = 1 * 1 = 1
  - i = 1: leftProduct = 1, result[1] = 1 * 1 = 1, leftProduct = 1 * 2 = 2
  - i = 2: leftProduct = 2, result[2] = 1 * 2 = 2, leftProduct = 2 * 3 = 6
  - i = 3: leftProduct = 6, result[3] = 1 * 6 = 6, leftProduct = 6 * 4 = 24
- After First Pass: result = [1, 1, 2, 6]
- Second Pass (Right Side Product):
    - i = 3: rightProduct = 1, result[3] = 6 * 1 = 6, rightProduct = 1 * 4 = 4
    - i = 2: rightProduct = 4, result[2] = 2 * 4 = 8, rightProduct = 4 * 3 = 12
    - i = 1: rightProduct = 12, result[1] = 1 * 12 = 12, rightProduct = 12 * 2 = 24
    - i = 0: rightProduct = 24, result[0] = 1 * 24 = 24, rightProduct = 24 * 1 = 24
- After Second Pass: result = [24, 12, 8, 6]
- Final Output: [24, 12, 8, 6]
*/