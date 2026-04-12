# 323. Number of Connected Components in an Undirected Graph
# Link: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

from typing import List

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        # we will create an adjacency list for the graph
        adj = [[] for _ in range(n)]

        # we will use a visited array to keep track of the visited nodes
        visit = [False] * n
        ## we will populate the adjacency list with the edges
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

            
        #dfs
        # this dfs will mark all the nodes in the same component as visited
        def dfs(node):
            for neighbors in adj[node]:
                #if the neighbor is not visited, we will visit it and mark it as visited
                if not visit[neighbors]:
                    visit[neighbors] = True
                    dfs(neighbors)
        

        res = 0
        # we will iterate through all the nodes, if the node is not visited, we will 
        for node in range(n):
            # if the node is not visited, we will mark it as visited and call 
            # dfs to mark all the nodes in the same component as visited, 
            # and we will increment the result by 1
            if not visit[node]:
                visit[node] = True
                dfs(node)
                # increment the result by 1 because we found a new component
                res+=1
        return res