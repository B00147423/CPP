
# 45. Permutations
# Link: https://leetcode.com/problems/permutations/
from typing import List
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.res = []
        self.backtrack(nums, [])
        return self.res
        
    def backtrack(self, nums, perm):
        
        if len(perm) == len(nums):
            self.res.append(perm[:])
            return

        for n in nums:
            if n in perm:
                continue
            perm.append(n)
            self.backtrack(nums, perm)
            perm.pop()


print(Solution().permute([1,2,3]))
print(Solution().permute([[7]]))