#include <unordered_set>
class Solution {
public:
    int findFinalValue(std::vector<int>& nums, int original) {
        std::unordered_set<int> s(nums.begin(), nums.end());

        while (s.count(original)) {
            original *= 2;
        }

        return original;
    }
};