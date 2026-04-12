# 309. Best Time to Buy and Sell Stock with Cooldown
# Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        memo = [[-1] * 2 for _ in range(len(prices))]

        def dfs(i, state):
            if i >= len(prices):
                return 0

            if memo[i][state] != -1:
                return memo[i][state]

            if state == 0:
                buy_path = dfs(i + 1, 1) - prices[i]
                cooldown = dfs(i + 1, 0)
                memo[i][0] = max(buy_path, cooldown)
            else:
                sell_path = dfs(i + 2, 0) + prices[i]
                cooldown = dfs(i + 1, 1)
                memo[i][1] = max(sell_path, cooldown)

            return memo[i][state]

        return dfs(0, 0)