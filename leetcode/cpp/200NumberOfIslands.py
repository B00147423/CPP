#Leetcode Problem 200: Number of Islands
#link: https://leetcode.com/problems/number-of-islands/description/
from typing import List

    #Leetcode Problem 200: Number of Islands
#link: https://leetcode.com/problems/number-of-islands/description/
class Solution:
    def numIslands(self, grid):
        if not grid:
            return 0

        num_islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    self.dfs(grid, i, j)
                    num_islands += 1

        return num_islands

    def dfs(self, grid, r, c):
        if (
            r < 0
            or c < 0
            or r >= len(grid)
            or c >= len(grid[0])
            or grid[r][c] != "1"
        ):
            return
        grid[r][c] = "0"

        self.dfs(grid, r - 1, c)
        self.dfs(grid, r + 1, c)
        self.dfs(grid, r, c - 1)
        self.dfs(grid, r, c + 1)

        
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        visit = set()
        def dfs(r, c):
            if (r < 0 or r == ROWS or c < 0 or 
                c == COLS or grid[r][c] == "0" or 
                (r, c) in visit):
                return
            visit.add((r, c))
            for dr, dc in directions:
                dfs(r + dr, c + dc)


        islands = 0

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == "1" and (r, c) not in visit:
                    dfs(r, c)
                    islands += 1

        return islands
    
    #time complexity big O(M*N) because we traverse the entire grid once
    ## Space: O(M*N) worst case due to recursion stack

