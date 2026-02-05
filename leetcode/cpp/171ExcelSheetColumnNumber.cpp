// Define a class named Solution as required by LeetCode
#include <string>

#include <iostream>
using namespace std;
class Solution {
public:
    // Function that converts an Excel column title (like "AB") to its corresponding number (like 28)
    int titleToNumber(string columnTitle) {
        
        // Initialize result to 0; this will accumulate the final column number
        int result = 0;
        // Loop through each character in the input string from left to right
        for (int i = 0; i < columnTitle.size(); i++){
            // Update result using base-26 conversion: 
            // multiply current result by 26 and add the 1-based value of the current letter
            result = result * 26 + (columnTitle[i] - 'A' + 1);
            // Print intermediate result for debugging (optional; can be removed in final submission)
            cout << "\nres: " << result;
        }
        // Return the final computed column number
        return result;
    }
};