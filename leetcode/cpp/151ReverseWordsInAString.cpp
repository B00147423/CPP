// 151. Reverse Words in a String
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
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

// Time complexity: O(n) where n is the length of the input string
// Space complexity: O(n) for storing the words in the vector and the result string

int main() {
    Solution solution;
    string input = " Hello   World ";
    string output = solution.reverseWords(input);

    std::cout << output << endl;  // ← THIS LINE

    return 0;
}