# Leetcode 647. Palindromic Substrings

class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        res = 0
        for i in range(n):
            res += self.countPalindrome(s, i, i)
            res += self.countPalindrome(s, i, i + 1)
        return res

    def countPalindrome(self, s, l, r):
        count = 0
        while  l >= 0 and r < len(s) and s[l] == s[r]:
            count += 1
            l -= 1
            r += 1
        return count

