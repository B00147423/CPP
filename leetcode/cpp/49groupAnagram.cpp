#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
// This code defines a function to group anagrams from a list of strings.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Key: char-count string, Value: list of anagrams
        unordered_map<string, vector<string>> res;  
         // For each string in input
        for (const auto& s : strs) { 
            // Initialize a count for each letter (a-z)
            vector<int> count(26, 0);  
            // Count each character in the string
            for(char c : s){
                count[c - 'a']++;  // 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
            }

            // Convert the count array into a string key (e.g., "1,0,0,0,1,...")
            // Start with count of 'a'
            string key = to_string(count[0]);  
            cout << "key: " << key << endl;
            for(int i = 1; i < 26; i++){
                key += "," + to_string(count[i]);  // Append counts for 'b' to 'z'
            }
            // Add the string to its corresponding key group
            res[key].push_back(s);
        }

        // Convert the map into a vector of vectors (expected output format)
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);  // Each value in the map is a group of anagrams
        }
        return result;
    }


};

int main() {
    Solution solution;
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(input);

    // Print the result
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << "]" << endl;
    }

    return 0;
};