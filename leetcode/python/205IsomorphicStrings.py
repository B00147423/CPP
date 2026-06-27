#Leetcode 205. Isomorphic Strings
#link: https://leetcode.com/problems/isomorphic-strings/
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:

        if len(s) != len(t):
            return False

        mapChar = {}
        used_t = set()   # keep track of characters in t already mapped

        for i in range(len(s)):
            if s[i] in mapChar:
                if mapChar[s[i]] != t[i]:
                    return False
            else:
                if t[i] in used_t:
                    return False
            mapChar[s[i]] = t[i]
            used_t.add(t[i])
        return True

