# 347. Top K Frequent Elements
from typing import List
from collections import defaultdict
import heapq


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        freq = defaultdict(int)

        for num in nums:
            freq[num] += 1

        heap = []

        for num, count in freq.items():
            heapq.heappush(heap, (count, num))

            if len(heap) > k:
                heapq.heappop(heap)

        res = []
        
        for cnt, num in heap:
            res.append(num)
        return [num for count, num in heap]



class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        freqCount = {}
        
        for i in range(len(nums)):
            freqCount[nums[i]] = freqCount.get(nums[i], 0 ) +1

        arr = []
        for num, cnt in freqCount.items():
            arr.append([cnt, num])
        arr.sort()

        res = []

        while len(res) < k:
            res.append(arr.pop()[1])
        return res
