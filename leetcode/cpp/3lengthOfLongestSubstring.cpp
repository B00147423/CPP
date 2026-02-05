#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;

        unordered_set<char> seen;
        int maxSubstringLenght = 0;
        for(int right = 0; right < s.size(); right++){
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxSubstringLenght = max(maxSubstringLenght, right - left+1);
        }

        return maxSubstringLenght;

    }
};

/*
    Time: Linear → O(n)
    Space: Constant → O(1) (because of fixed character set)
*/