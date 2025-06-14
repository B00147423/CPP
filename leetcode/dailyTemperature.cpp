#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack;   // Stack to store indices of temperatures
        vector<int> result(temperatures.size(), 0);  // Initialize result with 0s

        // Start iterating backward from the second last element
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            // While the stack is not empty and the current temperature is greater than the one at the index in the stack
            while (!stack.empty() && temperatures[i] >= temperatures[stack.top()]) {
                stack.pop();  // Pop elements that are not useful
            }
            // If stack is not empty, it means we found a warmer temperature in the future
            if (!stack.empty()) {
                result[i] = stack.top() - i;  // Calculate the number of days until the next warmer temperature
            }
            // Push the current index onto the stack
            stack.push(i);
        }

        return result;  // Return the result vector
    }
};

int main() {
    Solution solution;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = solution.dailyTemperatures(temperatures);

    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;

    return 0;
}