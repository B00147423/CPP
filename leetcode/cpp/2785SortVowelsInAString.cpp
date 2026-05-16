// 2785. Sort Vowels in a String
// link: https://leetcode.com/problems/sort-vowels-in-a-string/description/

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
class Solution {

    auto isVowel(char c) {
        return  c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
public:
    std::string sortVowels(std::string s) {

        std::unordered_map<char, int> freq;
        std::vector<char> vows;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];

            if(isVowel(c)){
               freq[c]++;
               vows.push_back(c); 
            }
        }
        std::sort(vows.begin(), vows.end());        
        int i = 0;
        for (char& c : s) {
            if (isVowel(c)) {
                c = vows[i++];
            }
        }


        return s;
    }
};