#include <iostream>
#include <vector>


class Solution {
public:
    int maxSumDivThree(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<long long>> dp(n+1, std::vector<long long>(3));


        dp[n][0] = 0;
        dp[n][1] = dp[n][2] = -1e18; 
        
        for(int pos = n-1; pos >= 0; pos--){
            for(int mod = 0; mod < 3; mod++){
  
                long long skipRow = dp[pos + 1][mod];
                std::cout << "\nskipRow : "<< skipRow;
                int new_mod = (mod + nums[pos]) % 3;
                std::cout << "\nnewMode: "<< new_mod;
                long long take = nums[pos] + dp[pos + 1][new_mod];
                dp[pos][mod] = std::max(skipRow, take);

            }
        }
        return dp[0][0];
    }
};