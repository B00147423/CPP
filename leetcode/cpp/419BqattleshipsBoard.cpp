#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) 
            return 0;
        
        int ROWS = board.size();
        int COLS = board[0].size();
        int count = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'X' && 
                    (r == 0 || board[r-1][c] != 'X') && 
                    (c == 0 || board[r][c-1] != 'X')) {
                    count++;
                }
            }
        }
        return count;
    }
};