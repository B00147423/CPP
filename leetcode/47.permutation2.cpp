
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());    
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false); 
        vector<int> current;
        backtrack(nums, current, used, result);
        return result;
    }

    void backtrack(vector<int>& nums, vector<int>& current,  
                    vector<bool>& used, vector<vector<int>>& result){
        
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue; 
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;
        
            current.push_back(nums[i]);
            used[i] = true;

            backtrack(nums, current, used, result);

            current.pop_back();
            used[i] = false;
        }
    }
};