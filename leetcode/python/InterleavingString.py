# 97. Interleaving String
# Link: https://leetcode.com/problems/interleaving-string/
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        
        if len(s1) + len(s2) != len(s3):
            return False
        
        memo = {}

        def dfs(i, j):
            if (i, j) in memo:
                return memo[(i, j)]
            
            k = j + i
            
            if k == len(s3):
                return True

            res = False

            if i < len(s1) and s1[i] == s3[k]:
                res = dfs(i + 1, j)
            
            if not res and j < len(s2) and s2[j] == s3[k]:
                res = dfs(i, j + 1)
            
            memo[(i, j)] = res

            return res
        return dfs(0, 0)
