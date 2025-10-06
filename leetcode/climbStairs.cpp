#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>

class Solution {
public:
    int climbStairs(int n) {

        // base case: if there are 1 or 2 steps,
        // there's only 1 or 2 ways to climb respectively
        if (n <= 2) {
            return n;
        }

        // create a dp array of size n + 1 (so we can use 1-based indexing)
        // dp[i] = number of distinct ways to reach step i
        vector<int> dp(n + 1);

        // base cases:
        // 1 step → only 1 way (just 1 step)
        dp[1] = 1;

        // 2 steps → two ways:
        // (1+1) or (2)
        dp[2] = 2;

        // fill the dp array from step 3 to n
        for (int i = 3; i <= n; i++) {

            // to reach step i:
            // you can come from (i-1) using one step
            // or from (i-2) using a double step
            // so total ways = dp[i-1] + dp[i-2]
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // dp[n] now holds the total number of ways to reach the top
        return dp[n];
    }
};
