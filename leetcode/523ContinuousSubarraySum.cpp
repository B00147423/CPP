#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixMod = 0;
        unordered_map<int, int> modSeen;
        modSeen[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            prefixMod = (prefixMod + nums[i]) % k;

            if (modSeen.find(prefixMod) != modSeen.end()) {
                // ensures that the size of subarray is atleast 2
                if (i - modSeen[prefixMod] > 1) {
                    return true;
                }
            } else {
                // mark the value of prefixMod with the current index.
                modSeen[prefixMod] = i;
            }
        }

        return 0;
    }
};

/*
Time complexity

O(n)

Reason:

    - You traverse the array once (size n)
    - Each step does:
    = constant-time arithmetic

Space complexity
O(n) in the worst case

Reason:
    - In the worst case, each prefix produces a new remainder
    - You store at most one entry per index in the map
*/