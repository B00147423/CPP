
#include <vector>

class Solution {
public:
    std::vector<bool> prefixesDivBy5(std::vector<int>& nums) {

        std::vector<bool> result;
        int current = 0;
        

        for(int i = 0; i < nums.size(); i++){
            current = (current * 2 + nums[i]) % 5;
            if(current == 0){
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }   
        return result;
    }
};

