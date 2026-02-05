#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0, maxLen = 0, maxFreq = 0;
        
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);
            
            if ((right - left + 1) - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

/*
Time: O(n)

Space: O(1)
*/