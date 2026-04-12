# 11. Container With Most Water
# Link: https://leetcode.com/problems/container-with-most-water/
class Solution:
    def maxArea(self, height):
        
        l, r = 0, len(height) - 1
        maxArea = 0
        while l < r:
            maxArea = max(maxArea, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return maxArea
