#11. Container With Most Water
# Leetcode problem: https://leetcode.com/problems/container-with-most-water/
from typing import List


class Solution:
    def maxArea(self, heights: List[int]) -> int:


        left = 0
        right = len(heights) - 1
        maxWater = float('-inf')
        res = 0
        while left < right:
            width = right - left
            containerHeight = min(heights[left], heights[right])
            area = width * containerHeight


            maxWater = max(maxWater, area) 

            if heights[left] < heights[right]:
                left += 1
            else:
                right -= 1
        return maxWater