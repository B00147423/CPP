# 567. Permutation in String
# Link: https://leetcode.com/problems/permutation-in-string/
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        n = len(s1)
        m = len(s2)

        s1Count = [0] * 26
        s2Count = [0] * 26

        for i in range(n):
            s1Count[ord(s1[i]) - ord('a')] += 1
            s2Count[ord(s2[i]) - ord('a')] += 1

        if s1Count == s2Count:
            return True
        
        for r in range(n, m):
            s2Count[ord(s2[r]) - ord('a')] += 1
            s2Count[ord(s2[r - n]) - ord('a')] -= 1
            if s2Count == s1Count:
                return True

        return False
    
    
