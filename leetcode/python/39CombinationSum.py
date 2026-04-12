# 39. Combination Sum
# Link: https://leetcode.com/problems/combination-sum/
from typing import List

class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        res = []
        self.backtrack(nums, 0, [], target, res)
        return res

    def backtrack(self, nums, start, subset, remaining, res):
        if remaining == 0:
            res.append(subset[:])
            return

        for i in range(start, len(nums)):
            if nums[i] > remaining:
                continue

            subset.append(nums[i])
            self.backtrack(nums, i, subset, remaining - nums[i], res)
            subset.pop()

if __name__ == "__main__":
    s = Solution()
    print(s.combinationSum([2, 3, 6, 7], 7))