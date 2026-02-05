#include <vector>

using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Create a DP array of size (amount + 1)
        // Initialize every value to amount + 1 (a value larger than any possible answer)
        // This represents "infinity" — meaning we haven't found a valid way yet.
        vector<int> dp(amount + 1, amount + 1);

        // Base case: 0 coins are needed to make amount 0
        dp[0] = 0;

        // Loop through all amounts from 1 up to 'amount'
        for (int i = 1; i <= amount; i++) {

            // Try every coin value for the current amount i
            for (int j = 0; j < coins.size(); j++) {

                // If the current coin can fit into the current amount
                // (i.e., we can use this coin without going negative)
                if (coins[j] <= i) {

                    // dp[i - coins[j]] = fewest coins to make (i - coin value)
                    // +1 = use one more coin (the current one)
                    // Take the minimum between the current dp[i] and the new possibility
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        // If dp[amount] is still larger than amount,
        // it means we couldn't make the target amount with given coins
        // Otherwise, return the fewest coins found
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
