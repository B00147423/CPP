#include <iostream>
#include <string>

class Solution {
public:
    int numSub(std::string s) {
        const long long MOD = 1000000007;
        long long currSubLength = 0;
        long long result = 0;

        for(char c : s){
            if(c == '1')
            {
                currSubLength++;
                result = (result + currSubLength) % MOD;
            }
            else
            {
                currSubLength = 0;
            }
        }
        return result;
    }
};