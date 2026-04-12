# 128. Longest Consecutive Sequence
# Link: https://leetcode.com/problems/longest-consecutive-sequence/
from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)
        longest = 0
        for nums in numSet:
            if (nums-1) not in numSet:
                length = 1
                while (nums+length) in numSet:
                    length +=1
                longest = max(length, longest)
        return longest
    

s = Solution()
test = [
    [],
    [5],
    [1,2,3,4],
    [100,4,200,1,3,2],
    [1,2,2,3],
    [-2,-1,0,1],
    [10,30,20],
]

for nums in test:
    result = s.longestConsecutive(nums)
    print("\nOutput :  ", result)