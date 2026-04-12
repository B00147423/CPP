# 78. Subsets
# Link: https://leetcode.com/problems/subsets/
from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        def backtrack(start, subset):
            res.append(subset[:])

            for i in range(start, len(nums)):
                subset.append(nums[i])
                backtrack(i + 1, subset)
                subset.pop()

        backtrack(0, [])
        return res

if __name__ == "__main__":
    s = Solution()
    print(s.subsets([1, 2, 3]))
    