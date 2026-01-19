#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;
        int n = s.size();
        int left = 0;

        // Step 1: extract words
        while (left < n) {
            // skip spaces
            while (left < n && s[left] == ' ') {
                left++;
            }
            if (left >= n) break;

            int start = left;
            // read word
            while (left < n && s[left] != ' ') {
                left++;
            }

            words.push_back(s.substr(start, left - start));
        }

        // Step 2: build result in reverse order
        string result;
        for (int j = words.size() - 1; j >= 0; j--) {
            result += words[j];
            if (j != 0) result += " ";
        }
            
        return result;
    }
};