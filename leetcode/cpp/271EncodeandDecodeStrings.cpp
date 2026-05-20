//Leetcode  271. Encode and Decode Strings
// Link: https://leetcode.com/problems/encode-and-decode-strings/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Codec {

public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encodedString = "";

        for(string& word : strs){
            encodedString += to_string(word.size());
            encodedString.push_back('#');
            encodedString += word;
        }

        return encodedString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {


        vector<string> result;
        int startIndex = 0;

        while (startIndex < s.size()) { 
            int separatorIndex = s.find('#', startIndex);
            int wordSize = stoi(s.substr(startIndex, separatorIndex - startIndex));
            string word = s.substr(separatorIndex + 1, wordSize);
            result.push_back(word);
            startIndex = separatorIndex + 1 + wordSize;
        }
        return result;
    }
};