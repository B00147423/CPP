// 1559. Detect Cycles in 2D Grid
// Given a 2D grid of characters, return true if there is a cycle in the
// grid, or false otherwise.
// A cycle is a path of length 4 or more in the grid that starts and ends at
// the same cell and consists of the same character. From a given cell, you
// can move to any of the next 4 directions: up, down, left, or
// right. You cannot move to the same cell twice in a cycle, except for the
// first and last cells.
// https://leetcode.com/problems/detect-cycles-in-2d-grid/
#include <vector>
using namespace std;


class Solution {


public:
    bool containsCycle(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        for (int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(!visited[i][j]){
                    if (dfs(grid, visited, i, j,-1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited,
            int r, int c, int prev_r, int prev_c, char targetChar) {

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int ROWS = grid.size();
        int COLS = grid[0].size();

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS) {
            return false;
        }
        if (grid[r][c] != targetChar) return false;
        

        if (visited[r][c]) {
            return true;
        }


        visited[r][c] = true;
        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];
            //skip visited 
            if (nr == prev_r && nc == prev_c) {
                continue;
            }

            if (dfs(grid, visited, nr, nc, r, c, targetChar)) {
                return true;
            }
        }
        return false;
    }
};