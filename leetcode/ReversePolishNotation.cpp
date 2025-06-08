#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

class Solution {

public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> ms;
        for(string& c : tokens){
            if(c == "+"){
                int a = ms.top(); ms.pop();
                int b = ms.top(); ms.pop();
                ms.push(b + a);
            }else if(c == "-"){
                int a = ms.top(); ms.pop();
                int b = ms.top(); ms.pop();
                ms.push(b - a);
            }else if(c == "*"){
                int a = ms.top(); ms.pop();
                int b = ms.top(); ms.pop();
                ms.push(b * a);
            }else if( c == "/"){
                int a = ms.top(); ms.pop();
                int b = ms.top(); ms.pop();
                ms.push(b / a);
            }else{
                ms.push(stoi(c));
            }
        }
        return ms.top();

    }
};

int main() {
    Solution solution;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int result = solution.evalRPN(tokens);
    cout << "Result of Reverse Polish Notation: " << result << endl; // Output should be 9
    return 0;
}