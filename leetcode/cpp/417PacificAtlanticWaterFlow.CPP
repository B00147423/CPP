
// 417. Pacific Atlantic Water Flow
//Link: https://leetcode.com/problems/pacific-atlantic-water-flow/
#include <vector>
using namespace std;
class Solution {
    vector<pair<int,int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));
        vector<vector<int>> res;

        for (int c = 0; c < COLS; c++) {
            dfs(heights, pacific, 0, c, heights[0][c]);
            dfs(heights, atlantic, ROWS - 1, c, heights[ROWS - 1][c]);
        }

        for (int r = 0; r < ROWS; r++) {
            dfs(heights, pacific, r, 0, heights[r][0]);
            dfs(heights, atlantic, r, COLS - 1, heights[r][COLS - 1]);
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }

private:
    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int r,
             int c,
             int prevHeight) {
        
        int ROWS = heights.size();
        int COLS = heights[0].size();

        if (r < 0 || r >= ROWS || c < 0 || c >= COLS) return;
        if (visited[r][c]) return;
        if (heights[r][c] < prevHeight) return;

        visited[r][c] = true;

        for (auto [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;
            dfs(heights, visited, nr, nc, heights[r][c]);
        }
    }
};
