#include <vector>
#include <iostream>

class Solution {
public:
    bool kLengthApart(std::vector<int>& nums, int k) {
        int prev = -1;  // last seen index of 1 (or -1 if none seen yet)
/*

[1,0,0,0,1,0,0,1]
 0 1 2 3 4 5 6 7
i = 1;

prev = -1 // no prev 1 found 

prev becomes index 0 which is 1

i goes forward until it reaches another 1;
i = 4
prev = 0
we then have i = index 4

4-0-1 = 3

distance  = 3


prev = i = prev = index 4

i goes until reaches index 7

7-4-1 - 2 

reaches the end of nums 

*/
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1){
                if(prev != -1 && i-prev -1 < k){
                    return false;
                }
                prev = i;
            }
        }
    return true;
    }
};