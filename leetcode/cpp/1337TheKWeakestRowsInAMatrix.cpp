//1337. The K Weakest Rows in a Matrix
//link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        int row_level = mat.size();
        int col_level = mat[0].size();
        for (int r = 0; r < row_level; r++){
            int count = 0;
            for(int c = 0; c < col_level; c++)
                if(mat[r][c] == 1){
                    count++;
                }
            pq.push({count, r});
        }
        vector<int> result;

        while(k > 0){
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return result;
    }
};

