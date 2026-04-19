# 763. Partition Labels
from typing import List
class Solution:
    def partitionLabels(self, s: str) -> List[int]:

        lastIndex = {}
        for i, c in enumerate(s):
            lastIndex[c] = i
        print(lastIndex)
        res = []
        size = end = 0
        for i, c in enumerate(s):
            size += 1
            print(i)
            end = max(end, lastIndex[c])
   
            if i == end:
                
                res.append(size)
             

                size = 0
        return res