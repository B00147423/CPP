#include <vector>

class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
     int result = 0;

     for(int num : nums){
        if(num % 3 != 0){
            result++;
        }
     }   
    return result;
    }
};