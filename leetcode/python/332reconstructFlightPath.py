# 332. Reconstruct Itinerary
# Link: https://leetcode.com/problems/reconstruct-itinerary/

from collections import defaultdict
from typing import List
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:

        graph = defaultdict(list)
        for from_i, to_i in tickets:
            graph[from_i].append(to_i)
            print(graph)
        
        for key in graph:
            graph[key].sort()
            print(graph)

        res = []


        def dfs(node):

            while graph[node]:
                next_dest = graph[node].pop(0)
                dfs(next_dest)
            res.append(node)

        dfs('JFK')
        res.reverse()
        return res