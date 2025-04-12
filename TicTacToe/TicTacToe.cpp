#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';
int movesCount = 0;

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    cout << "\033[2J\033[H"; // Clear screen and move cursor to top left
    cout << "Tic-Tac-Toe\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---------\n";
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool checkDraw() {
    return movesCount == 9;
}

void makeMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        movesCount++;
        printBoard(); // Update the board display
        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!\n";
            exit(0);
        } else if (checkDraw()) {
            cout << "It's a draw!\n";
            exit(0);
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    } else {
        cout << "Invalid move! Try again.\n";
    }
}

int main() {
    initializeBoard();
    printBoard();
    while (true) {
        int row, col;
        cout << "Player " << currentPlayer << ", enter row and column (0, 1, 2): ";
        cin >> row >> col;
        makeMove(row, col);
    }
    return 0;
}
