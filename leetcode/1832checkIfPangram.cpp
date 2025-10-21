
#include <iostream>
#include <unordered_set>
#include  <string>
using namespace std;
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> myset;

        for(char c : sentence){
            myset.insert(c);
        }
        if(myset.size() == 26){
            return true;
        }
        return false;
    }
};