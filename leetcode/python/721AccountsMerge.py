#Leetcode 721. Accounts Merge
# Link: https://leetcode.com/problems/accounts-merge/
from collections import defaultdict
from typing import List


class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.rank = [1] * n   # optional but recommended

    def find(self, x):
        if x != self.par[x]:
            self.par[x] = self.find(self.par[x])  # path compression
        return self.par[x]


    def union(self, p1, p2):
        p1 = self.find(p1)
        p2 = self.find(p2)

        if p1 == p2:
            return False # already connexted

        #union by rank (attach smaller tree to bigger one)
        if self.rank[p1] > self.rank[p2]:
            self.par[p2] = p1
        elif self.rank[p1] < self.rank[p2]:
            self.par[p1] = p2
        else:
            self.par[p2] = p1
            self.rank[p1] +=1
        return True



class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        uf = UnionFind(len(accounts))
        emailToAcc = {}  # email -> index of acc

        for i, a in enumerate(accounts):
            for e in a[1:]:
                if e in emailToAcc:
                    uf.union(i, emailToAcc[e])
                else:
                    emailToAcc[e] = i

        emailGroup = defaultdict(list)
        for e, i in emailToAcc.items():
            leader = uf.find(i)
            emailGroup[leader].append(e)

        res = []
        for i, emails in emailGroup.items():
            name = accounts[i][0]
            res.append([name] + sorted(emailGroup[i]))
        return res
