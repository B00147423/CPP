# 678. Valid Parenthesis String

class Solution:
    def checkValidString(self, s: str) -> bool:

        openBracket = 0
        closedBracket = 0

        for c in s:
            if c == "(":
                openBracket += 1
                closedBracket += 1
            elif c == ")":
                openBracket -= 1
                closedBracket -= 1
            else:  # "*"
                openBracket -= 1      # treat as ")"
                closedBracket += 1     # treat as "("

            if closedBracket < 0:
                return False

            openBracket = max(openBracket, 0)

        return openBracket == 0
