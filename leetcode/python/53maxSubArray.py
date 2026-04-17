# 53. Maximum Subarray
from typing import List
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = nums[0]

        resMaxSubArray = nums[0]

        for i in range(1,  len(nums)):
            resMaxSubArray = max(resMaxSubArray + nums[i], nums[i])

            res = max(res, resMaxSubArray)
        return res