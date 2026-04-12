# 684. Redundant Connection
# Link: https://leetcode.com/problems/redundant-connection/
from typing import List


class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n + 1)]  # 1-based indexing
        self.rank = [1] * (n + 1)

    def find(self, x):
        while x != self.par[x]:
            self.par[x] = self.par[self.par[x]]
            x = self.par[x]
        return x

    def union(self, x1, x2):
        p1, p2 = self.find(x1), self.find(x2)

        if p1 == p2:
            return False  # cycle detected

        if self.rank[p1] > self.rank[p2]:
            self.par[p2] = p1
            self.rank[p1] += self.rank[p2]
        else:
            self.par[p1] = p2
            self.rank[p2] += self.rank[p1]

        return True


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
            uf = UnionFind(len(edges))
            for p1, p2 in edges:
                if not uf.union(p1, p2):
                    return [p1, p2]