#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
 //

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;

        for (char ch : s) {

            // case 1: digit
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
                continue;
            }

            // case 2: opening bracket
            if (ch == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
                continue;
            }

            // case 3: closing bracket
            if (ch == ']') {
                string decodedString = stringStack.top();
                stringStack.pop();

                int repeat = countStack.top();
                countStack.pop();

                for (int i = 0; i < repeat; i++) {
                    decodedString += currentString;
                }

                currentString = decodedString;
                continue;
            }

            // case 4: letter
            currentString += ch;
        }

        return currentString;
    }
};

// Time Complexity: O(n*k) where n is the length of the string and k is the maximum repeat count
// Space Complexity: O(m) where m is the maximum depth of nested brackets

/*
dry run:
s = "3[a2[c]]"
ch | k | currentString |   stringStack   | countStack
-----------------------------------------------------------
 3 | 3 |      ""       |       []        |    []
 [ | 0 |      ""       |      [""]       |   [3]
 a | 0 |     "a"      |      [""]       |   [3]
 2 | 2 |     "a"      |      [""]       |   [3]
 [ | 0 |      ""       |     ["","a"]    |   [3,2]
 c | 0 |     "c"      |     ["","a"]    |   [3,2]
 ] | 0 |    "acc"     |      [""]       |    [3]
 ] | 0 |   "accaccacc"|       []        |    []
*/