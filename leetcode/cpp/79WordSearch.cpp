// 79. Word Search
// https://leetcode.com/problems/word-search/
#include <iostream>
#include <vector>
using namespace std;

class Solution {

    vector<vector<int>> directions = {
    {1, 0},   // down
    {-1, 0},  // up
    {0, 1},   // right
    {0, -1}   // left
    };
public:
    bool exist(vector<vector<char>>& board, string word) {

    int ROWS = board.size();
    int COLS = board[0].size();
 
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(board[r][c] == word[0]){
                    if(dfs(r, c, 0, board, word, ROWS, COLS)){
                        return true;
                    }
                }
            }
        }
        return false;
    }


    bool dfs(int r, int c, int index, vector<vector<char>>& board, string& word,int ROWS, int COLS){
        if(index == word.size()){
            return true;
        }

        if(r < 0 || r >= ROWS || c < 0 || c >= COLS) return false;
        if(board[r][c] != word[index]) return false;

        char temp = board[r][c]; // save the letter so we can go back and undo it 
        board[r][c] = '#'; // mark visited


        for(auto& d : directions){
            int nr = r+d[0];
            int nc = c+d[1];
            if (dfs(nr, nc, index + 1, board, word, ROWS, COLS))return true; // SUCCESS → we exit early
        }

        board[r][c] = temp;
        return false;
    }
};

/*
dry run:
board = [
    ['A','B','C','E'],
    ['S','F','C','S'],
    ['A','D','E','E']
    ]
word = "ABCCED"
start:
r=0, c=0, index=0
board[0][0] == word[0] -> 'A' == 'A'
mark visited:
board = [
    ['#','B','C','E'],
    ['S','F','C','S'],
    ['A','D','E','E']
    ]

dfs(1,0,1) -> down
r=1, c=0, index=1
board[1][0] == word[1] -> 'S' == 'B' -> false

dfs(-1,0,1) -> up
r=-1, c=0, index=1 -> out of bounds -> false

dfs(0,1,1) -> right
r=0, c=1, index=1
board[0][1] == word[1] -> 'B' == 'B'
mark visited:
board = [
    ['#','#','C','E'],
    ['S','F','C','S'],
    ['A','D','E','E']
    ]
dfs(1,1,2) -> down
r=1, c=1, index=2
board[1][1] == word[2] -> 'F' == 'C' -> false


dfs(-1,1,2) -> up
r=-1, c=1, index=2 -> out of bounds -> false

dfs(0,2,2) -> right
r=0, c=2, index=2
board[0][2] == word[2] -> 'C' == 'C'
mark visited:
board = [
    ['#','#','#','E'],
    ['S','F','C','S'],
    ['A','D','E','E']
    ]

dfs(1,2,3) -> down
r=1, c=2, index=3
board[1][2] == word[3] -> 'C' == 'C'
mark visited:
board = [
    ['#','#','#','E'],
    ['S','F','#','S'],
    ['A','D','E','E']
    ]

dfs(2,2,4) -> down
r=2, c=2, index=4
board[2][2] == word[4] -> 'E' == 'E'
mark visited:
board = [
    ['#','#','#','E'],
    ['S','F','#','S'],
    ['A','D','#','E']
    ]

dfs(3,2,5) -> down
r=3, c=2, index=5 -> out of bounds -> false

dfs(1,2,5) -> up
r=1, c=2, index=5
board[1][2] == word[5] -> '#' == 'D' -> false

dfs(2,3,5) -> right
r=2, c=3, index=5
board[2][3] == word[5] -> 'E' == 'D' -> false

dfs(2,1,5) -> left
r=2, c=1, index=5
board[2][1] == word[5] -> 'D' == 'D'
mark visited:
board = [
    ['#','#','#','E'],
    ['S','F','#','S'],
    ['A','#','#','E']
    ]
    
dfs(3,1,6) -> down
r=3, c=1, index=6
index == word.size() -> 6 == 6 -> true
return true all the way back up
*/