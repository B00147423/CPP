#include <vector>
#include <string>

using namespace std;
class Solution {
    vector<int> result;
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;
        result.clear();
        // Base case: if the string is empty, return an empty list
        if (expression.length() == 0) return results;

        // Base case: if the string is a single character, treat it as a number
        // and return it
        if (expression.length() == 1) {
            results.push_back(stoi(expression));
            return results;
        }
        // If the string has only two characters and the first character is a
        // digit, parse it as a number
        if(expression.length() == 2  && isdigit(expression[0])){
            results.push_back(stoi(expression));
            return results;
        }

        // Recursive case: iterate through each character
        for(int i = 0; i < expression.length(); i++){
            char currentChar = expression[i];
        // Split the expression into left and right parts
        vector<int> leftResults =
            diffWaysToCompute(expression.substr(0, i));
        vector<int> rightResults =
            diffWaysToCompute(expression.substr(i + 1));

            for(int leftValue : leftResults){
                for(int rightValue : rightResults){
                    int computedResult = 0;

                    switch(currentChar){
                        case '+':
                            computedResult = leftValue + rightValue;
                            break;
                        case '-':
                            computedResult = leftValue - rightValue;
                            break;
                        case '*':
                            computedResult = leftValue * rightValue;
                            break;
                    }
                    result.push_back(computedResult);
                }
            }

        }
    }
};