// 51. N-Queens
// https://leetcode.com/problems/n-queens/
#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<vector<string>> resutlBoard;;
    vector<string> board;
    vector<bool> column, diagonal1, diagonal2;

public:
    vector<vector<string>> solveNQueens(int n) {
        /*

    input n = 4

    output: 
    [
    q...      
    ...q
    q...
    ..q.
    ]
    make n*n grid with q palced in spots that cant atatck each other?
    
    each row has 1 q
    each diagonal has 1 Q


    q moves sides and diagonally. 

        
    bad = 
    []
        q...      
        ...q
        .q..
        ....
    ]
    good =
    ]
        q...      
        ...q
        q...
        ..q.
    ]
    good = 
    ]
        .q..      
        ...q
        q...
        ..q.
    ]

     0 to  6
        diag 0 = [0]

        diag 1 = [1, 1]

        diag 2 = [2, 2, 2]

        diag 3 = [3, 3, 3, 3]

        diag 4 = [4, 4, 4]

        diag 5 = [5, 5]

        diag 6 = [6]

    ]
        
*/

    board = vector<string>(n, string(n, '.'));
    column = vector<bool>(n, false);
    diagonal1 = vector<bool>(2*n-1, false);
    diagonal2 = vector<bool>(2*n-1, false);
    solvenQueenBacktrack(0, n);
    return resutlBoard;

    }
private:
    void solvenQueenBacktrack(int row, int n){

        //base
        if(row == n){
            resutlBoard.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++){
            //column[c] = up/down, 
            //diagonal1[row-c+n-1] top-left → bottom-right)
            //diagonal2[row+c], top-right → bottom-left)
            if(column[c] || diagonal1[row-c+n-1] || diagonal2[row+c] ) continue;

            board[row][c] = 'Q';
            column[c] = diagonal1[row-c+n-1] =  diagonal2[row+c] = true;

            solvenQueenBacktrack(row+1, n);

            board[row][c] = '.';
            column[c] =  diagonal1[row-c+n-1] = diagonal2[row+c] = false;
        }
    }
}; 

/*Q
dry run ::
n = 4
board = 
[
"....",
"....",
"....",
"...."
]

n = 4

row 0:
- place Q at (0,0)

row 1:
- try (1,2) → dead end
- backtrack
- place Q at (1,3)

row 2:
- place Q at (2,1)

row 3:
- place Q at (3,2)
→ solution found

backtrack and continue for other solutions

*/