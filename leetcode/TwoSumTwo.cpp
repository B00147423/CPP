#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {

            // Create a hash map to store the indices of the numbers
            unordered_map<int, int> numMap;

            // Iterate through the numbers
            for (int i = 0; i < numbers.size(); i++) {
                // Calculate the complement
                int complement = target - numbers[i];

                // Check if the complement exists in the map
                if (numMap.find(complement) != numMap.end()) {
                    // If found, return the indices (1-based)
                    return {numMap[complement] + 1, i + 1};
                }

                // Store the index of the current number in the map
                numMap[numbers[i]] = i;
            }
            
        //     for (int i = 0; i < numbers.size(); i++) {
        //         for (int j = i + 1; j < numbers.size(); j++) {
        //             if (numbers[i] + numbers[j] == target) {
        //                 return {i + 1, j + 1}; // Return 1-based indices
        //             }
        //         }
        //     }
        //     return {}; // Return an empty vector if no solution is found
            
        }
    };

int main(){
    Solution s;
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    vector<int> result = s.twoSum(numbers, target);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl; // Output: 1 2
    return 0;
}
    
