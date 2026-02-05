#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int wordLength = 0;
        int i = s.size() -1;
        std::cout << " i :" << i; 
        while(i >= 0 && s[i] ==  ' '){
            i--;
        }

        while(i >= 0 && s[i] != ' '){
            wordLength++;
            i--;
        }

        return wordLength;
    }
};