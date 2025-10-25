#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // Get the number of real balloons
        int n = nums.size();

        // Create a new array with 1s added at both ends (padding)
        vector<int> newNums(n + 2, 1);

        // Create a 2D DP table initialized to -1 (means “not computed yet”)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        // Copy original nums into the middle of newNums
        for (int i = 0; i < n; i++) {
            newNums[i + 1] = nums[i];
            cout << "\nnewNums: " << newNums[i];
        }

        // Start recursion: full range (excluding the two padded 1s)
        return dfs(newNums, 1, newNums.size() - 2, dp);
    }

    // Recursive function to compute max coins between indexes l and r
    int dfs(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        // Base case: if the range is empty (no balloons left)
        if (l > r) return 0;

        // If this subproblem has already been solved, return the stored result
        if (dp[l][r] != -1) return dp[l][r];

        // Initialize this cell to 0 (we’ll compute the best result below)
        dp[l][r] = 0;

        // Try bursting each balloon i between l and r last
        for (int i = l; i <= r; i++) {
            // Coins gained from bursting balloon i last,
            // using boundaries l-1 and r+1 (the neighbors)
            int coins = nums[l - 1] * nums[i] * nums[r + 1];

            // Add coins gained from recursively solving left and right subranges
            coins += dfs(nums, l, i - 1, dp) + dfs(nums, i + 1, r, dp);

            // Update dp[l][r] with the maximum coins possible for this range
            dp[l][r] = max(dp[l][r], coins);
        }

        // Return the best result for range (l, r)
        return dp[l][r];
    }
};
