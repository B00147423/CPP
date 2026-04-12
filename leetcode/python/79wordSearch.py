# Leetcode 79. Word Search
# Link: https://leetcode.com/problems/word-search/
from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        directions = [[-1,0], [1,0], [0,-1], [0,1]]

        ROWS, COLS = len(board), len(board[0])
        visited = [[False for _ in range(COLS)] for _ in range(ROWS)]

        def backtrack(row, col, i):

            if i == len(word):
                return True
            if (row < 0 or col < 0 or row >= ROWS or col >= COLS or
                word[i] != board[row][col] or visited[row][col]):
                return False
            visited[row][col] = True

            for dr, dc in directions:
                if backtrack(row + dr, col + dc, i + 1):
                    return True

            visited[row][col] = False
            return False
                        

        for r in range(ROWS):
            for c in range(COLS):
                if backtrack(r, c, 0):
                    return True
        return False