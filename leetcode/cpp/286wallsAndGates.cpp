#include <vector>
#include <queue>

class Solution {
public:
    void wallsAndGates(std::vector<std::vector<int>>& rooms) {
        if (rooms.empty()) return;
        int rows = rooms.size();
        int cols = rooms[0].size();
        std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        std::queue<std::pair<int,int>> queue;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if(rooms[r][c] ==0){
                    queue.push({r,c});
                }
            }
        }

        while(!queue.empty()){
            auto curr = queue.front();
            queue.pop();

            int r = curr.first;
            int c = curr.second;

            for(auto d : dirs){
                int nr = r + d.first;
                int nc = c + d.second;
                if(nr < 0 || nr >= rows || nc < 0 || nc >= cols){
                    continue;
                }

                if (rooms[nr][nc] != INT_MAX) {
                    continue;
                }

                rooms[nr][nc] = rooms[r][c] + 1;
                queue.push({nr, nc});
            }
        }
    }
};