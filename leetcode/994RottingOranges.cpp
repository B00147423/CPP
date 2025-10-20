#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // count fresh oranges and enqueue all rotten ones
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2)
                    q.push({r, c});
                else if (grid[r][c] == 1)
                    fresh++;
            }
        }

        int minutes = 0;
        int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (auto& d : directions) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols || grid[nr][nc] != 1)
                        continue;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh--;
                }
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};