#include <vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        // number of steps in the cost array
        int n = cost.size();

        // dp[i] = minimum total cost to reach step i
        // note: we create n+1 because we can go "beyond" the last step (the top)
        vector<int> dp(n + 1);

        // we start before the first two steps, so dp[0] and dp[1] are both 0
        // (no cost to start)
        dp[0] = 0;
        dp[1] = 0;

        // from step 2 onward, compute the minimum cost to reach each step
        for (int i = 2; i <= n; i++) {

            // two options:
            // 1 come from step (i - 1) and pay cost[i - 1]
            // 2️come from step (i - 2) and pay cost[i - 2]
            // choose the cheaper option
            dp[i] = min(dp[i - 1] + cost[i - 1],
                        dp[i - 2] + cost[i - 2]);
        }

        // dp[n] represents the min cost to reach the top (past the last stair)
        return dp[n];
    }
};
