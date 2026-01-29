#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size()-1;

        int jumpCount = 0;
        int currJump = 0;
        int farthest = 0;

        for(int i = 0; i < n; i++){
            farthest = std::max(farthest, i + nums[i]);
            if(i == currJump){
                jumpCount++;
                currJump = farthest;
            }
        }
        return jumpCount;

    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)

/*
dry run:
nums = [2,3,1,1,4]
loop[ 0..3] because we don't need to jump from the last index
start:
i | nums[i] | farthest = max(prev_farthest, i+nums[i]) | currJump (derived)                 | jumpCount
-----------------------------------------------------------------------------------------------------
- |    -    |                  0                        | 0 (init)                           | 0
0 |    2    | max(0, 0+2) = 2                           | i==0 → currJump = farthest = 2     | 1
1 |    3    | max(2, 1+3) = 4                           | i!=2 → currJump stays 2            | 1
2 |    1    | max(4, 2+1) = 4                           | i==2 → currJump = farthest = 4     | 2
3 |    1    | max(4, 3+1) = 4                           | i!=4 → currJump stays 4            | 2
End:

                            
return jumpCount = 2
*/

