# 261. Graph Valid Tree
# Link: https://leetcode.com/problems/graph-valid-tree/
from typing import List

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        visited = set()


        graph = []

        for i in range(n):
            graph.append([])

        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        def dfs(currNode, parent):
            visited.add(currNode)

            for neighbor in graph[currNode]:
                if neighbor == parent:
                    continue
                
                if neighbor in visited:
                    return False

                if not dfs(neighbor, currNode):
                    return False
            return True
        
        return dfs(0, -1) and len(visited) == n
