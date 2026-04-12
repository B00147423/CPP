#215. Kth Largest Element in an Array
# Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
import heapq
from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        heap = []

        for n in nums:
            heapq.heappush(heap, n)
            if len(heap) > k:
                heapq.heappop(heap)
        return heap[0]