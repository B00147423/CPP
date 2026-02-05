#include <vector>
class Solution {
public:
    int numberOfPaths(std::vector<std::vector<int>>& grid, int k) {
        int mod = 1e9 + 7; 
        int m = grid.size();
        int n = grid[0].size();

        std::vector<std::vector<std::vector<int>>> dp(m, std::vector<std::vector<int>>(n, std::vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int r = 0; r < k; r++) {
                    // If we have paths to current cell with remainder r
                    if(dp[i][j][r] > 0){
                        // Move right
                        if(j + 1 < n){
                            int new_remainder = (r + grid[i][j+1]) % k;
                            dp[i][j+1][new_remainder] = (dp[i][j+1][new_remainder] + dp[i][j][r] % mod);
                        }
                        // Move down
                        if (i + 1 < m)
                        {
                            int new_remainder = (r + grid[i+1][j]) % k;
                            dp[i+1][j][new_remainder] = (dp[i+1][j][new_remainder] + dp[i][j][r]% mod);
                        }
                    }
                }
            }
        }
    return dp[m-1][n-1][0];
    }
};