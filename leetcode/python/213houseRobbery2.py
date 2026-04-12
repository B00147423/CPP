# 213. House Robber II
# Link: https://leetcode.com/problems/house-robber-ii/
from typing import List




class Solution:
    def rob(self, nums: List[int]) -> int:
        return max(
            self.helper(nums[1:]),
            self.helper(nums[:-1])
        )

    def helper(self, nums):

        if not nums:
            return 0
        
        n = len(nums)

        if n == 1:
            return nums[0]

        dp = [0] * (n)

        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, n):
            dp[i] = max(dp[i-1], nums[i] + dp[i-2])
        return dp[-1]