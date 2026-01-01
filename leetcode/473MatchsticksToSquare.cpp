// LeetCode: Matchsticks to Square
#include <numeric>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool makesquare(std::vector<int>& matchsticks) {

        // declare variable to hold total sum
        long long sum;

        // accumulate total length of all matchsticks
        sum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0LL);

        // if total length isn't divisible by 4, square is impossible
        if (sum % 4 != 0) return false;

        // target side length = total / 4
        int target = sum / 4;

        // create 4 sides initialized to 0
        std::vector<int> sides(4, 0);

        // sort sticks from largest to smallest (prunes faster)
        std::sort(matchsticks.rbegin(), matchsticks.rend());

        // start backtracking from the first stick
        return backtrack(matchsticks, sides, 0, target);
    }

private:
    bool backtrack(std::vector<int>& matchsticks, std::vector<int>& sides, int index, int target){

        // if we've placed all sticks, we formed a valid square
        if (index == matchsticks.size()){
            return true;
        }

        // try placing current stick on each of the 4 sides
        for (int i = 0; i < 4; i++) {

            // check if stick fits on this side without exceeding target
            if (sides[i] + matchsticks[index] <= target) {

                // place stick on side i
                sides[i] += matchsticks[index];

                // attempt to place the next stick
                if (backtrack(matchsticks, sides, index + 1, target)){
                    return true; // success path
                }

                // undo placement (backtrack)
                sides[i] -= matchsticks[index];
            }

            // optimization: if side is still 0 after trying,
            // no point trying other empty sides — symmetric state
            if (sides[i] == 0) break;
        }

        // no placement worked → fail path
        return false;
    }
};
