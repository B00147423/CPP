#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();                // get number of houses

        if (n == 0) return 0;               // no houses → no money
        if (n == 1) return nums[0];         // one house → rob it

        // Exclude the first house (can't take both first and last)
        int money1 = helper(vector<int>(nums.begin() + 1, nums.end()));
        cout << "m1 : " << money1;          // print result for excluding first

        // Exclude the last house
        int money2 = helper(vector<int>(nums.begin(), nums.end() - 1));
        cout << "m2 : " << money2;          // print result for excluding last

        // Return the higher total (best option)
        return max(money1, money2);
    }

private:
    int helper(vector<int> nums) {
        int n = nums.size();                // number of houses in this subproblem

        if (n == 0) return 0;               // no houses → no money
        if (n == 1) return nums[0];         // one house → rob it

        vector<int> dp(n);                  // dp[i] = best total up to house i
        dp[0] = nums[0];                    // first house → take it
        dp[1] = max(nums[0], nums[1]);      // pick richer of first two

        // fill dp table for the rest
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1],          // skip current house
                        nums[i] + dp[i - 2] // rob current + best up to i-2
                       );
        }

        return dp.back();                   // last element = best total overall
    }
};
