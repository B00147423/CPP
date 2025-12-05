#include <algorithm>
#include <vector>
#include <unordered_map>


class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        

        std::unordered_map<int, bool> mp;

        for(int num : nums){
            if (num > 0) mp[num] = true;
        }

        int i = 1;

        while(true){
            if(mp.find(i) == mp.end())
            {
                return i;
            }
            i++;
        }
        return 0;
    }
};