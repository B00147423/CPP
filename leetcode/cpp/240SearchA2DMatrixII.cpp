// 240. Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        cout << "\n m = " << m ;
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;

       while (row < m && col >= 0) {
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] > target){
                col--;
            }else {
                row++;
            }
        }
        return false;
    }
};

/*
Matrix (target = 5):

[
 [ 1,  4,  7, 11, 15 ],
 [ 2,  5,  8, 12, 19 ],
 [ 3,  6,  9, 16, 22 ],
 [10, 13, 14, 17, 24 ],
 [18, 21, 23, 26, 30 ]
]

m = 5
n = 5

Start:
row = 0
col = n - 1 = 4
--------------------------------

Step 1:
matrix[0][4] = 15
15 > 5  → col--
row = 0, col = 3

Step 2:
matrix[0][3] = 11
11 > 5  → col--
row = 0, col = 2

Step 3:
matrix[0][2] = 7
7 > 5   → col--
row = 0, col = 1

Step 4:
matrix[0][1] = 4
4 < 5   → row++
row = 1, col = 1

Step 5:
matrix[1][1] = 5
5 == 5  → FOUND → return true
--------------------------------

Loop condition:
while (row < m && col >= 0)

*/