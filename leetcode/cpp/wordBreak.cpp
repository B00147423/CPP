#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
    // A memoization map to store whether a substring starting at index i can be segmented.
    // Key: index i, Value: true if s[i:] can be broken into words from wordDict, false otherwise.
    unordered_map<int, bool> memo;

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Base case: an empty string (starting at s.length()) is always a valid segmentation.
        memo[s.length()] = true;

        // Start DFS (Depth-First Search) from index 0.
        return dfs(s, wordDict, 0);
    }

    bool dfs(string& s, vector<string>& wordDict, int i) {
        // If we've already computed whether s[i:] can be segmented, return the stored result.
        if (memo.find(i) != memo.end()) {
            return memo[i];
        }

        // Try every word in the dictionary to see if it matches the substring starting at index i.
        for (const string& word : wordDict) {
            // Check that the word fits within the remaining part of s
            // and that the substring matches the current dictionary word.
            if (i + word.length() <= s.length() && s.substr(i, word.length()) == word) {
                // If the substring s[i + word.length():] can also be segmented, store and return true.
                if (dfs(s, wordDict, i + word.length())) {
                    memo[i] = true;
                    return true;
                }
            }
        }

        // If no valid segmentation found starting from index i, store false in memo.
        memo[i] = false;
        return false;
    }
};
