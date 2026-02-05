
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// C++ Solution
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        unordered_map<int, int> counter;
        for (int num : nums) counter[num]++;
        vector<int> comb;
        backtrack(counter, comb, nums.size(), results);
        return results;
    }
    void backtrack(unordered_map<int, int>& counter, vector<int>& comb, int N,
                   vector<vector<int>>& results) {
        if (comb.size() == N) {
            results.push_back(comb);
            return;
        }
        for (auto& item : counter) {
            int num = item.first;
            int count = item.second;
            if (count == 0) continue;
            comb.push_back(num);
            counter[num]--;
            backtrack(counter, comb, N, results);
            comb.pop_back();
            counter[num]++;
        }
    }
};
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