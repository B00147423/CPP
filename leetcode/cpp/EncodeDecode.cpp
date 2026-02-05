#include <iostream>
#include <unordered_map>
using namespace std;
#include <stack>
#include <string>

class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString;
        for(const string& str : strs){
            encodedString += to_string(str.size()) + "#" + str;
        }
        return encodedString;   
    }

    vector<string> decode(string s) {
        vector<string> decodedStrings;
        int i = 0;
        while (i < s.size()) {
            // Find the position of the delimiter which indicates the end of the length
            int j = i;
            while (s[j] != '#') j++;
            
            // Extract the length of the next string
            int length = stoi(s.substr(i, j - i));
            // Move past the delimiter
            i = j + 1;
            
            // Extract the string of the specified length
            decodedStrings.push_back(s.substr(i, length));
            // Move to the next length specification
            i += length;
        }
        return decodedStrings;
    }
};