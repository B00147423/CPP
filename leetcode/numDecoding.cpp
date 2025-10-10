#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // Create a dp array (dynamic programming table) with one extra slot.
        // dp[i] will store the number of ways to decode the substring starting at index i.
        vector<int> dp(s.size() + 1);

        // Base case: there's 1 way to decode an empty string (do nothing).
        dp[s.size()] = 1;

        // Loop backwards through the string, from the end toward the start.
        for (int i = s.size() - 1; i >= 0; i--) {

            // If the current character is '0', there are 0 ways to decode from here
            // because '0' cannot map to any letter.
            if (s[i] == '0') {
                dp[i] = 0;
            } 
            else {
                // Otherwise, take the number of ways from the next position (single-digit decoding).
                dp[i] = dp[i + 1];

                // If the next two characters form a valid two-digit number (10–26),
                // add the number of ways to decode the rest of the string after those two digits.
                if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        // dp[0] contains the total number of ways to decode the entire string.
        return dp[0];
    }
};
