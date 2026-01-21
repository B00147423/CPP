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