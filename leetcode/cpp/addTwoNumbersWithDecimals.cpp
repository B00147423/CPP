/*
Example 1:

Input: str1 = "123.5943" and str2 = "11.2"
output: should be "134.7943"

Potential Solutions. Which is better?

Pad the smaller string with zeroes on the right hand side & then iterate backwards one character at a time and handle the carry.

Rip out the difference in length after the dot suffix and add directly to result. Then iterate backwards one character at a time and handle the carry.

see how 123.5943 has 3 more digit than 11.2 after the decimal, so result would start with 943 and change str1 to be 123.5, now merge as normal
*/

// 415. Add Strings
// link: https://leetcode.com/problems/add-strings/description/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string str1, string str2) {
        int dotPos1 = str1.find('.');
        string whole1 = str1.substr(0, dotPos1);
        string decimal1 = str1.substr(dotPos1 + 1);

        string whole2 = str2.substr(0, str2.find('.'));
        string decimal2 = str2.substr(str2.find('.') + 1);

        while(decimal1.size() < decimal2.size()){
            decimal1 += '0';
        }
        while(decimal2.size() < decimal1.size()){
            decimal2 += '0';
        }

        long long num1 = stoll(whole1 + decimal1);
        long long num2 = stoll(whole2 + decimal2);

        string total = to_string(num1 + num2);
        int decimalPlaces = decimal1.size();

        while(total.size() <= decimalPlaces){
            total = '0' + total;
        
        }

        string result = total.substr(0, total.size() - decimalPlaces)
                      + "."
                      + total.substr(total.size() - decimalPlaces);

        while (result.back() == '0') result.pop_back();
        if (result.back() == '.') result.pop_back();
                      
        return result;
    }
};
int main() {
    Solution sol;

    string str1 = "123.5943";
    string str2 = "11.2";

    cout << sol.addStrings(str1, str2) << endl; // 134.7943

    return 0;
}