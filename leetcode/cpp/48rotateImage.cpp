#include <vector>
#include <iostream>
using namespace std;
class Solution {
    
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        transpose(matrix);
        reflect(matrix);
    }

private:
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[j][i], matrix[i][j]);
            }
        }
    }

    void reflect(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int layers = n / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < layers; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    solution.rotate(matrix);

    // Output the rotated matrix
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}