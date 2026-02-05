#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;
            int n = nums.size();
                // Add this check (crucial for small inputs!)
            if (n < 4) return res;  // Edge case: Not enough elements
            
            for (int i = 0; i < n - 3; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
                
                // Early termination if min sum > target
                if ((long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
                // Skip if max sum < target
                if ((long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
    
                for (int j = i + 1; j < n - 2; j++) {
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates
                    
                    // Early termination for current j
                    if ((long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                    if ((long)nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;
    
                    int l = j + 1, r = n - 1;
                    while (l < r) {
                        long sum = (long)nums[i] + nums[j] + nums[l] + nums[r];
                        if (sum == target) {
                            res.push_back({nums[i], nums[j], nums[l], nums[r]});
                            while (l < r && nums[l] == nums[l + 1]) l++; // Skip duplicates
                            while (l < r && nums[r] == nums[r - 1]) r--;
                            l++; r--;
                        } 
                        else if (sum < target) l++;
                        else r--;
                    }
                }
            }
            return res;
        }
    };