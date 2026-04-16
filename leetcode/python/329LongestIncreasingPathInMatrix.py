# 329. Longest Increasing Path in a Matrix
#Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

from typing import List



class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        memo = {}
        ROWS, COLS = len(matrix), len(matrix[0])


        def backtrack(r, c):
            if (r, c) in memo:
                return memo[(r, c)]

            res = 1

            directions = [(1,0), (-1,0), (0,1), (0,-1)]

            for dr, dc in directions:
                nr = r + dr
                nc = c + dc

                if 0 <= nr < ROWS and 0 <= nc < COLS:
                    if matrix[nr][nc] > matrix[r][c]:
                        res = max(res, 1 + backtrack(nr, nc))

            memo[(r, c)] = res
            return res
        
        ans = 0
        for r in range(ROWS):
            for c in range(COLS):
                ans = max(ans, backtrack(r, c))

        return ans