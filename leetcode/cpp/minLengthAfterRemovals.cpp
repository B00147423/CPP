
#include <string>
#include <vector>
#include<iostream>

using namespace std;
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int countA = 0;
        int countB = 0;

        for(char c : s){
            if(c == 'a')
            {
                countA++;
            }else{
                countB++;
            }
        }
        return abs(countA - countB);
    }
};


int main() {
    Solution sol;

    vector<string> tests = {
        "aabbab",
        "aaaa",
        "aaabb"
    };

    for (string &s : tests) {
        cout << "Input: " << s << "\n";
        cout << "Output: " << sol.minLengthAfterRemovals(s) << "\n\n";
    }

    return 0;
}