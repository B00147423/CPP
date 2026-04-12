# 70. Climbing Stairs
# Link: https://leetcode.com/problems/climbing-stairs/
#Recursion
class Solution:
    def climbStairs(self, n: int) -> int:
        def dfs(i):
            if i >= n:
                return i == n
            return dfs(i+1) + dfs(i+2)
        return dfs(0)
#this approach has a time complexity of O(2^n) because it explores all possible 
# combinations of steps. The space complexity is O(n) due to the recursive call stack.
#space complexity: O(n) due to the recursive call stack, 
# where n is the height of the recursion tree.

#TOP DOWN DP
class Solution:
    def climbStairs(self, n: int) -> int:
        cache = [-1] * n

        def dfs(i):
            if i >=n:
                return i==n
            if cache[i] != -1:
                return cache[i]
            cache[i] = dfs(i+1) + dfs(i+2)
            return cache[i]
        return dfs(0)
#This approach has a time complexity of O(n) 
# because each unique state is computed only once and stored in the cache. 

# The space complexity is O(n) due to the recursive call stack and the cache array, 
# where n is the height of the recursion tree.

#bottom up DP
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        dp = [0] * (n + 1)
        dp[1], dp[2] = 1, 2
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n]
    
#This approach has a time complexity of O(n)
# because it iterates through the range from 3 to n, 
# computing the number of ways to climb to each step. 
# The space complexity is O(n) due to the dp array that stores the number of ways 
# to climb to each step,