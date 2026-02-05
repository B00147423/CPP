/*
We want O(log(m * n)) time.

Key idea:
- Treat the 2D matrix as if it were a single 1D sorted array.
- Do ONE binary search over all elements.

We DO NOT scan rows.
We DO NOT restart binary search per row.

We pretend the matrix looks like this:

Index:  0  1  2  3   4   5   6   7   8   9  10  11
Value:  1  3  5  7  10  11  16  20  23  30  34  60

Binary search picks a middle index (mid).

To access the real matrix cell:
- row = mid / COLS
- col = mid % COLS

This converts the 1D index back into (row, col).
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

 //we eed to get row and column so that we can get mdipoint of each row
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        //we eed to get row and column so that we can get mdipoint of each row
        int left = 0;
        int right = ROWS * COLS - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            cout<< "mid = " <<mid;
             cout<< "\nCOL= " <<COLS;
            int r = mid / COLS;
            int c = mid % COLS;

            if (matrix[r][c] < target) {
                left = mid + 1;
            } else if (matrix[r][c] > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};