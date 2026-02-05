#include <iostream>
using namespace std;
#include <unordered_map>
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> myChar;
        myChar['{'] = '}';
        myChar['('] = ')';
        myChar['['] = ']';
        std::stack<char> stack;
        
        for (char c : s) {
            // If c is an opening bracket
            if (myChar.find(c) != myChar.end()) {
                stack.push(c);
            } else {
                // If c is a closing bracket
                if (stack.empty()) return false; // No matching opening bracket
                char top = stack.top();
                stack.pop();
                if (myChar[top] != c) return false; // Mismatched pair
            }
        }
        
        return stack.empty(); // Ensure all opening brackets are matched
    }
};