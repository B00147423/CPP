#include <vector>
#include <iostream>
class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        
        int l = 0;
        int total = 0;
        int res = INT_MAX;
        for (int r = 0; r < nums.size(); r++) {
            total += nums[r];
            std::cout << "\ntotal" << target;
            std::cout << "\n  ";
            while (total >= target) {
                std::cout << "\n--- WHILE START ---";
                std::cout << "\nr = " << r;
                std::cout << "\nl = " << l;
                std::cout << "\ntotal (before) = " << total;

                int windowLen = r - l + 1;
                res = std::min(res, windowLen);
                std::cout << "\nwindow length = " << windowLen;
                std::cout << "\nres (min length so far) = " << res;

                std::cout << "\nsubtracting nums[" << l << "] = " << nums[l];
                total -= nums[l];
                l++;

                std::cout << "\ntotal (after) = " << total;
                std::cout << "\nl (after increment) = " << l;
                std::cout << "\n--- WHILE END ---\n";
            }
        }
        return res == INT_MAX ? 0 : res;

    }
};

