#include <vector>
using namespace std;

class Solution {
    int ROW, COL;
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        /*
        FROM,POSITION i

        u can walk one step,m left right up or down;
        

           i = position  WE'RE At
                    R C
            RIGHT =(0,1)
            LEFT  =(0,-1)
            UP  =  (-1,0)
            DOWN = (1,0)
           {
            000
            0i0
            000
           }

            cant visit same cell more than ocne,

            visited = false or true;
            if cell is 0 gold we skip
            
            start and sto pfro many position

            WE can do dfs backtrack so that we cnas udn othe decision we make in roder to maximize the gold 
            Time complexity:
                "Exponential."
                "This is exponential because we're exploring all possible simple paths through the gold cells, not just visiting each cell once."

                That's the direct answer:

                What: Exponential time

                Why: Exploring all possible paths

            Space complexity:
                "Linear to the grid size."
                "The space complexity is O(m*n) in the worst case, where m and n are the grid dimensions. 
                This is due to the visited array used to track which cells have been visited during the DFS traversal."

        */

        ROW = grid.size();
        COL = grid[0].size();

        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        int maxGold = 0;


        for(int r = 0; r < ROW; r++){
            for(int c = 0; c < COL; c++){
                if (grid[r][c] > 0) {
                    maxGold = max(maxGold, dfs(grid, r, c, visited));
                }
            }
        }
        return maxGold;
    }
private:
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited){
        visited[r][c] = true;
        int best = 0;


        for (auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr >= 0 && nr < ROW && nc >= 0 && nc < COL &&
                !visited[nr][nc] && grid[nr][nc] > 0) {
                best = max(best, dfs(grid, nr, nc, visited));
            }
        }
        visited[r][c] = false;
        return grid[r][c] + best;;
    }
};