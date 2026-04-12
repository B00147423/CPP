# 139. Word Break
# Link: https://leetcode.com/problems/word-break/
from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # We can use a dictionary to store the results of 
        # previously computed indices
        memo = {len(s) : True}
        # index is the starting point of the substring we want to check
        def dfs(index): 
            # If we have already computed the result for this index, return it
            if index in memo: 
                return memo[index]
            # Check if the substring starting from index can be 
            # segmented into words in the dictionary
            for word in wordDict:
                if s[index : index + len(word)] == word:
                    if dfs(index + len(word)):
                        memo[index] = True
                        return True
            memo[index] = False # Store the result
            return False
        return dfs(0)