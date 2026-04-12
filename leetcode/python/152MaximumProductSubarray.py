# 152. Maximum Product Subarray

from typing import List



class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n, res = len(nums), nums[0]
        prefix = suffix = 0

        for i in range(n):
            prefix = nums[i] * (prefix or 1)

            suffix = nums[n - 1 - i] * (suffix or 1)
            print(suffix)
            res = max(res, max(prefix, suffix))
        return res