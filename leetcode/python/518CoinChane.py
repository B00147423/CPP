# 518. Coin Change 2
from typing import List
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        coins.sort()
        memo = [[-1] * (amount + 1) for _ in range(len(coins) + 1)]

        def dfs(i, amount):

            if amount == 0:
                return 1

            if i >= len(coins):
                return 0

            if memo[i][amount] != -1:
                return memo[i][amount]


            res = dfs(i + 1, amount)

            if amount >= coins[i]:
                res += dfs(i, amount - coins[i])
            
            memo[i][amount] = res
            return res

        return dfs(0, amount)