#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') 
            return;

        grid[i][j] = '0'; // mark as visited

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m * n; i++) {
            int row = i / n;
            int col = i % n;

            if (grid[row][col] == '1') {
                islands++;
                dfs(grid, row, col);
            }
        }

        return islands;
    }
};

int main() {
    Solution solution;

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    int result = solution.numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
