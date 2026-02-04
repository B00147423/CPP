// 221. Maximal Square
// https://leetcode.com/problems/maximal-square/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
    
        int maxSide = 0;
   
        if(matrix.empty() || matrix[0].empty()) return 0;


        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;  // first row or column
                    } else {
                        dp[i][j] = 1 + min({
                            dp[i-1][j],     // top
                            dp[i][j-1],     // left
                            dp[i-1][j-1]    // top-left
                        });
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        return maxSide * maxSide;
    }
};

/*

*/


