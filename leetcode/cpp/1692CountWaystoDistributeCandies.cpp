//Leetcode 1692. Count Ways to Distribute Candies
//Link: https://leetcode.com/problems/count-ways-to-distribute-candies/description/
#include <vector>
using namespace std;
class Solution {
    vector<vector<int>> memo;
    int MOD = 1e9 + 7;

public:
    int waysToDistribute(int n, int k) {
        
        memo = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        return dfs(n, k);
    }


private:
    int dfs(int n, int k) {
        if(n ==0 && k == 0) return 1;

        if(n == 0 || k == 0) return 0;
        if (k > n)return 0;

        if (memo[n][k] != -1){
            return memo[n][k];
        }

        long long takeNewBag = dfs(n-1, k-1);

        long long putInExistingBag = (long long)k * dfs(n - 1, k);
        return memo[n][k] = (takeNewBag + putInExistingBag) % MOD;

    }
};