# 743. Network Delay Time
from collections import defaultdict
from typing import List
import heapq
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:

        graph = defaultdict(list)
        dist = {i: float('inf') for i in range(1, n + 1)}
        dist[k] = 0
        heap = [(0, k)]

        for u, v, w in times:
            graph[u].append((v, w))
            print(graph)


        while heap:
            time, node = heapq.heappop(heap)
            for nei, weight in graph[node]:
                print(nei)
                new_time = time + weight
                print(new_time)

                if new_time < dist[nei]:
                    dist[nei] = new_time
                    heapq.heappush(heap, (new_time, nei))

        max_time = max(dist.values())
        if max_time == float('inf'):
            return -1

        return max_time
