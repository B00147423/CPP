#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> current;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        /*
            so can we have for exampekl 2 chsoen as many tiems as we want as long as it == target?
            so  if we target is 7 and we have combination 1,1,1,1,1,1,1; this would be not allowed because the frequency of the nums is different.
        */

                    
        backtrack(candidates, 0, target);
        return result;
    }
    void backtrack(vector<int>& candidates, int start, int remaining){

        if(remaining == 0){
            result.push_back(current);
            return;
        }

        if(remaining < 0) return;

        for(int i = start; i < candidates.size(); i++){
            current.push_back(candidates[i]);
            backtrack(candidates, i, remaining - candidates[i]);
            current.pop_back();
        }
    }
};