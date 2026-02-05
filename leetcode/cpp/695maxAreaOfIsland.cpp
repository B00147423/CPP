#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int  dfs(vector<vector<int>>& grid, int i, int j){
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
                return 0;
                
            grid[i][j] = 0;
            return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
        }   
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int maxArea = 0;
            int r = grid.size();
            int c = grid[0].size();

            for(int i = 0; i < r*c; i++){
                int row = i / c;
                int col = i % c;

            if (grid[row][col] == 1) {
                int area = dfs(grid, row, col);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    int result = solution.maxAreaOfIsland(grid);
    cout << "Max area of island: " << result << endl;

    return 0;
}