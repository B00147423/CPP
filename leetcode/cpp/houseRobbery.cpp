#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        // get how many houses there are
        int n = nums.size();
        
        // if there are no houses, we can't rob anything
        if (n == 0) return 0;

        // if there's only one house, just rob it
        if (n == 1) return nums[0];

        // create a dp array to store max money we can rob up to each house
        vector<int> dp(nums.size());

        // base case 1: rob the first house (only option)
        dp[0] = nums[0];

        // base case 2: choose the richer of the first two houses (can’t rob both)
        dp[1] = max(nums[0], nums[1]);

        // from the 3rd house onward, calculate the best option at each step
        for (int i = 2; i < n; i++) {

            // choice 1: skip this house -> dp[i-1]
            // choice 2: rob this house -> nums[i] + dp[i-2]
            // take whichever gives more money
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        // the last element in dp is the max money we can rob overall
        return dp[nums.size() - 1];
    }
};
