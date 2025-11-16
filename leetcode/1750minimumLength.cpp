#include <iostream>
#include <string>


class Solution {
public:
    int minimumLength(std::string s) {
        int l = 0, r = s.size()-1;
        
        
        while (l < r && s[l] == s[r]){
            char c = s[l];
            while(l <= r && s[l] == c)l++;

            while(l <= r && s[r] == c)r--;
        }

        return std::max(0, r-l+1);
    }
};