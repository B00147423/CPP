# 242. Valid Anagram
# Link: https://leetcode.com/problems/valid-anagram/
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        
        if len(s) != len(t):
            return False
        countS = {}
        countT = {}
        for i in range(len(s)):
            countS[s[i]] = countS.get(s[i], 0) +1
            countT[t[i]] = countT.get(s[i], 0) +1


        return countT == countS