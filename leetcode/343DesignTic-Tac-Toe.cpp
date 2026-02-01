// LeetCode Problem 343: Design Tic-Tac-Toe
// https://leetcode.com/problems/design-tic-tac-toe/

#include <vector>
#include <cstdlib>
using namespace std;

class TicTacToe {
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int anti_diagonal;
    int n;
public:
    TicTacToe(int n) {
        this->n = n;
        rows = vector<int>(n, 0);
        cols =  vector<int>(n, 0);
        diagonal = 0;
        anti_diagonal = 0;
    }
    
    int move(int row, int col, int player) {
        int playerVal = (player == 1) ? 1 : -1;

        rows[row] += playerVal;
        cols[col] += playerVal;

        if(row == col)
            diagonal+= playerVal;
        
        if(row+col == n-1)
            anti_diagonal +=playerVal;

        
        if( abs(rows[row]) == n ||
            abs(cols[col]) == n  ||
            abs(diagonal) == n  ||
            abs(anti_diagonal) == n){
            return player;
        }
        return 0;
    }
};


/*
dry run ::
TicTacToe toe(3); // TicTacToe object is instantiated with a board size of 3.
toe.move(0, 0, 1); // Player 1 moves at (0, 0). Returns 0 (no one wins).
toe.move(0, 2, 2); // Player 2 moves at (0, 2). Returns 0 (no one wins).
toe.move(2, 2, 1); // Player 1 moves at (2, 2). Returns 0 (no one wins).
toe.move(1, 1, 2); // Player 2 moves at (1, 1). Returns 0 (no one wins).
toe.move(2, 0, 1); // Player 1 moves at (2, 0). Returns 0 (no one wins).
toe.move(1, 0, 2); // Player 2 moves at (1, 0). Returns 0 (no one wins).
toe.move(2, 1, 1); // Player 1 moves at (2, 1). Returns 1 (Player 1 wins).
At each move, the corresponding row, column, and diagonals are updated.
When a player makes a move, we check if any of the counts reach n or -n,
indicating a win for Player 1 or Player 2, respectively.
The time complexity for each move is O(1) since we are only updating and checking a fixed number of counters.
space complexity is O(n) for storing the row and column counts.
*/