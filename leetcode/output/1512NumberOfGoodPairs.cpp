#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int countGoodPairs = 0;
        unordered_map<int, int> seen_counts;
        for(int rightPointer = 0; rightPointer < nums.size(); rightPointer++){
            int currentNum = nums[rightPointer];
            // If we've seen this number 2 times before, it means the 
        // current one can form 2 NEW pairs with those previous ones.
            if(seen_counts.find(currentNum) != seen_counts.end()){
                countGoodPairs += seen_counts[currentNum];
            } 
              // Update the 'Notes' so the next time we see this number, 
        // it knows about this one too.
        seen_counts[currentNum]++;
        }
    return countGoodPairs;
        
    }
};
 
int main() {
    Solution s;
    vector<int> nums = {1,2,3,1,1,3};
    cout << s.numIdenticalPairs(nums) << endl; // Output: 4
    return 0;   
}