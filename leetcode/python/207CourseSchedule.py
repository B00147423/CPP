# 207. Course Schedule
# Link: https://leetcode.com/problems/course-schedule/
from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = []
        visited = set()
        path = set()

        for i in range(numCourses):
            graph.append([])


        for course, prereq in prerequisites:
            graph[course].append(prereq)


        def dfs(currNode):

            if currNode in path:
                return False
            if currNode in visited:
                return True

            path.add(currNode)

            for neighbor in graph[currNode]:
                if not dfs(neighbor):
                    return False
            path.remove(currNode)
            visited.add(currNode)
            return True
        for i in range(numCourses):
            if not dfs(i):
                return False
        return True