#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
class Solution {
public:
    int minSubarray(std::vector<int>& nums, int p) {
        long long sum = 0;

        for(int num : nums){
            sum += num;
        }

        int target = sum % p;
        if(target == 0) return 0;

        std::unordered_map<int, int > mp;
        mp[0] = -1;
        int prefix = 0;
        int res = nums.size();

        for(int i = 0; i < nums.size(); i++){
            prefix = (prefix + nums[i]) % p;
            if(mp.count((prefix - target + p) % p)){
                int j = mp[(prefix - target + p) % p];
                std::cout << "\nj :" << j;
                res = std::min(res, i - j);
            }
            mp[prefix] = i;
        }


        if(res == nums.size()) {
            return -1;
        } else {
            return res;
        }
        
    }
};
