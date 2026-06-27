#Leetcode 205. Isomorphic Strings
#link: https://leetcode.com/problems/isomorphic-strings/
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:

        if len(s) != len(t):
            return False

        mapChar = {}
        for i in range(len(s)):
            if s[i] in mapChar:
                if mapChar[s[i]] != t[i]:
                    return False
            else:
                mapChar[s[i]] = t[i]
        return True

