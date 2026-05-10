// 2033. Minimum Operations to Make a Uni-Value Grid
//link: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/
#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<std::vector<int>>& grid, int x) {
        std::vector<int> nums_array;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int result = 0;
        //flatten the grid
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                nums_array.push_back(grid[r][c]);
            }
        }
        std::sort(nums_array.begin(), nums_array.end());

        int length = nums_array.size();
        int final_common_number = nums_array[length / 2];
        for(int num : nums_array){
            if (num % x != final_common_number  % x)
                return -1;
            result += std::abs(final_common_number - num) / x;
        }
        return result;
    }
};

