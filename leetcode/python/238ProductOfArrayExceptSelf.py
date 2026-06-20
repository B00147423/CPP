#Leetcode 238. Product of Array Except Self
#link: https://leetcode.com/problems/product-of-array-except-self/
from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        leftPrefix = 1
        rightPrefix = 1
        n = len(nums)
        productSum = [1] * n 

        for i in range(n):
            productSum[i] = leftPrefix
            leftPrefix = leftPrefix * nums[i]

        for j in range(n-1, -1, -1):
            productSum[j] *= rightPrefix

            rightPrefix = rightPrefix * nums[j]

        return productSum
