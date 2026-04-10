# 416. Partition Equal Subset Sum
from typing import List
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        memo = {}
        target = sum(nums) // 2

        if sum(nums) % 2 != 0:
            return False

        def dfs(i, currentSum):
            if (i, currentSum) in memo:
                return memo[(i, currentSum)]

            if currentSum == target:
                return True
            if i == len(nums) or currentSum > target:
                return False

            result =  dfs(i+1, currentSum) or dfs(i+1, currentSum + nums[i])

            memo[(i, currentSum)] = result
            return result

        return dfs(0, 0)