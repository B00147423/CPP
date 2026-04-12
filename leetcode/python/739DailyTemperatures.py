# 739. Daily Temperatures
# Link: https://leetcode.com/problems/daily-temperatures/
from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        
        n = len(temperatures)
        result = [0] * n
        stack = []

        for i, temp in enumerate(temperatures):
            while stack and temp > temperatures[stack[-1]]:
                previous_day = stack.pop()
                result[previous_day] = i - previous_day
            stack.append(i)


        return result
