# 74. Search a 2D Matrix
# Link: https://leetcode.com/problems/search-a-2d-matrix/
from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        row = len(matrix)
        col = len(matrix[0])

        left = 0
        right = row * col - 1

        while left <= right:
            mid = left+ (right - left) // 2
            row_index = mid // col
            col_index = mid % col
            print(col_index)
            if matrix[row_index][col_index] < target:
                left = mid+1
            elif matrix[row_index][col_index] > target:
                right = mid-1
            else:
                return  True
        return False
