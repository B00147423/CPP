# 787. Cheapest Flights Within K Stops
#dijkstra's algorithm with a min heap, we can use a 
# 2D array to keep track of the minimum cost to reach 
# each node with a certain number of stops. We will push the cost, 
# node, and stops into the min heap and update the costs accordingly. 
# Finally, we will return the minimum cost to reach the destination within K stops.
from collections import defaultdict
from typing import List
import heapq
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:



        graph = defaultdict(list)

        dist = [[float('inf')] * (k+2) for _ in range(n)]
        dist[src][0] = 0
        # cost, node, stops, 
        minHeap = [(0, src, 0)]

        for u, v, w in flights:
            graph[u].append((v, w))


        while minHeap:
            cost, node, stops, = heapq.heappop(minHeap)

            for nei, weight in graph[node]:
                new_cost = cost + weight# new cost

                if new_cost < dist[nei][stops+1]:
                    dist[nei][stops + 1] = new_cost
                    heapq.heappush(minHeap, (new_cost, nei, stops+1))

            min_cost = min(dist[dst])


            if min_cost == float('inf'):
                return -1
        return min_cost




