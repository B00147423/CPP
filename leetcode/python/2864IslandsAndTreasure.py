# 2864. Islands and Treasure
from ast import List


class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:

        ROWS, COLS = len(grid), len(grid[0])

        def dfs(r, c, distCount):

            if (
                r < 0 or r >= ROWS or
                c < 0 or c >= COLS or
                grid[r][c] == -1 or
                distCount > grid[r][c]
                ):
                return

            grid[r][c] = distCount

            dfs(r + 1, c, distCount + 1)
            dfs(r - 1, c, distCount + 1)
            dfs(r, c + 1, distCount + 1)
            dfs(r, c - 1, distCount + 1)

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 0:
                    dfs(r, c, 0)
