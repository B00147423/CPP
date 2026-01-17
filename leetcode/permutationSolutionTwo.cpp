#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        // Initialize frequency counts for the first window
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0; // Count how many characters match in frequency
        // Check for matches in the initial window
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) {
                matches++;
            }
        }

        // Slide the window over s2
        for (int r = s1.length(); r < s2.length(); r++) {
            if (matches == 26) {
                return true;
            }

            // Add the new character to the window (right side)
            int index = s2[r] - 'a';
            s2Count[index]++;
            if (s1Count[index] == s2Count[index]) {
                matches++;
            } else if (s1Count[index] + 1 == s2Count[index]) {
                matches--;
            }

            // Remove the old character from the window (left side)
            index = s2[r - s1.length()] - 'a';
            s2Count[index]--;
            if (s1Count[index] == s2Count[index]) {
                matches++;
            } else if (s1Count[index] - 1 == s2Count[index]) {
                matches--;
            }
        }

        return matches == 26;
    }
};




int main() {
    Solution s;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << s.checkInclusion(s1, s2) << endl; // Output: 1 (true)
    return 0;
}