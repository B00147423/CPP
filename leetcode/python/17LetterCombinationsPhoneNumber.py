# 17 Letter Combinations of a Phone Number
from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
                
        res = []
        if not digits:
            return []   
        mapDigitToMap = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }
        def backtrack(index, path):
            if index == len(digits):
                res.append(path)
                return

            letters = mapDigitToMap[digits[index]]

            for letter in letters:
                backtrack(index + 1, path + letter)
        backtrack(0, "")
        return res