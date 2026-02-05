// LeetCode Problem 167: Two Sum II - Input Array Is Sorted
//link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                result.push_back(left + 1);
                result.push_back(right + 1);
                break;
            }else if(sum < target){
                left++;
            }else{
                right--;
            }
        }
    return result;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
/*
dry run: 
numbers = [2,7,11,15], target = 9
left  right  sum        action  
    0     3     2 + 15 = 17   sum > target → right--
    0     2     2 + 11 = 13   sum > target → right--
    0     1     2 + 7  = 9    sum == target → store indices (1, 2) and break
    return [1, 2]
*/