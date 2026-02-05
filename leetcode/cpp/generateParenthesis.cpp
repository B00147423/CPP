#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

class Solution{
    public:
        void backtracking(int openN, int closedN, int n, std::vector<std::string>& res, std::string& stack) {
            // Base case: if the number of open and closed parentheses equals n, add the current combination to the result
            if( openN == n && closedN == n ){
                res.push_back(stack);
                return;
            }
            if (openN < n) {
                stack.push_back('(');
                backtracking(openN + 1, closedN, n, res, stack);
                stack.pop_back();
            }
            if (closedN < openN) {
                stack.push_back(')');
                backtracking(openN, closedN + 1, n, res, stack);
                stack.pop_back();
            }
        }


        std::vector<std::string> generateParenthesis(int n) {
            std::vector<std::string> res;
            std::string stack;
            backtracking(0, 0, n, res, stack);
            return res;
        }
};

int main (){
    Solution s;
    int n = 3;
    std::vector<std::string> result = s.generateParenthesis(n);
    for(const std::string& str : result){
        std::cout << str << std::endl;
    }
    return 0;
    
}