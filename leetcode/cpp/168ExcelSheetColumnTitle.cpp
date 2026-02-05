// Define a class named Solution as required by LeetCode
#include <string>

#include <iostream>
using namespace std;
// Start of class Solution
class Solution {
public:
    // Function to convert integer to Excel column title
    string convertToTitle(int columnNumber) {
        // Initialize empty result string
        string result = "";
        // Loop while columnNumber is greater than 0
        while(columnNumber > 0)
        {
            // Subtract 1 from columnNumber
            columnNumber--;
            // Append character corresponding to (columnNumber % 26) to result
            result += 'A' + (columnNumber % 26);
            // Print current result (for debugging)
            cout << "\nresult:" << result; 
            // Integer-divide columnNumber by 26
            columnNumber /= 26;
        }
        // Reverse the result string
        reverse(result.begin(), result.end());
        // Return the final string
        return result;
    }
};