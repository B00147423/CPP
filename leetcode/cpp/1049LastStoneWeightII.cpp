// 1049. Last Stone Weight II
//LINK: https://leetcode.com/problems/last-stone-weight-ii/

#include <vector>
#include <numeric>
using namespace std;


class Solution {
        vector<vector<int>> dp;
public:
    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = accumulate(stones.begin(), stones.end(), 0);
        int target = (stoneSum + 1) / 2;
        dp = vector<vector<int>>(stones.size(), vector<int>(target + 1, -1));
        return dfs(0, 0, stones, stoneSum, target);
    }
private:
    int dfs(int i, int totalSoFar, const vector<int>& stones, int stoneSum, int targetTotal){

        if(totalSoFar >= targetTotal || i == stones.size())
        {
            return abs(totalSoFar - (stoneSum - totalSoFar));
        }

        if(dp[i][totalSoFar] != -1){
            return dp[i][totalSoFar];
        }

        dp[i][totalSoFar] = min(
            dfs(i+1, targetTotal, stones, stoneSum, targetTotal),
            dfs(i+1, targetTotal + stones[i], stones, stoneSum, targetTotal)
        );
        return dp[i][totalSoFar];
    }
};