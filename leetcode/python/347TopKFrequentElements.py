from typing import List


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
