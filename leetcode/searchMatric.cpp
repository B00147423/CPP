#include <vector>
using namespace std;
#include <iostream>
// This code implements a binary search algorithm to find a target value in a 2D matrix.
// The matrix is assumed to be sorted in ascending order both row-wise and column-wise.

class Solution {

public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0, right = rows * cols - 1;
        if (rows == 0) return false;

        while(left <= right){
            int mid = left + (right - left) / 2;
            int r = mid / cols;
            int c = mid % cols;
            int val = matrix[r][c];

            if( val == target){
                return true;
            }else if( val  < target){
                left = mid +1;
            }else{
                right = mid -1;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60},
        {61, 66, 70, 80}
    };
    int target = 3;

    bool found = solution.searchMatrix(matrix, target);
    cout << "Target " << target << (found ? " found." : " not found.") << endl;

    return 0;
}