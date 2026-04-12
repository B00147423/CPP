# 133. Clone Graph
# Link: https://leetcode.com/problems/clone-graph/
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

# 133. Clone Graph

from typing import Optional

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        
        visited = {}
        def dfs(node):
            if not node:
                return None
            
            if node in visited:
                return visited[node]
        
            # create clone
            clone = Node(node.val)
            visited[node] = clone
            
            # clone neighbors
            for neighbor in node.neighbors:
                clone.neighbors.append(dfs(neighbor))
            
            return clone

        return dfs(node)