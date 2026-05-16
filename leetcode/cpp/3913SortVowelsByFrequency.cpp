// 3913. Sort Vowels by Frequency
// link: https://leetcode.com/problems/sort-vowels-by-frequency/description/
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
    auto isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    std::string sortVowels(std::string s) {
        std::unordered_map<char, int> freq;
        std::unordered_map<char, int> firstPos;
        std::vector<char> vows;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isVowel(c)) {
                freq[c]++;
                vows.push_back(c);

                if (!firstPos.count(c)) {
                    firstPos[c] = i;
                }
            }
        }

        std::sort(vows.begin(), vows.end(), [&](auto lhs, auto rhs) {
            if (freq[lhs] == freq[rhs]) {
                return firstPos[lhs] < firstPos[rhs];
            }
            return freq[lhs] > freq[rhs];
        });

        int i = 0;
        for (char& c : s) {
            if (isVowel(c)) {
                c = vows[i++];
            }
        }

        return s;
    }
};