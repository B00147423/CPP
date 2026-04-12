# 543. Diameter of Binary Tree
# Link: https://leetcode.com/problems/diameter-of-binary-tree/
from typing import Optional


class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:

        self.res = 0
        self.dfs(root)
        return self.res
        
    def dfs(self, node):
        if not node:
            return 0
        
        left = self.dfs(node.left)
        right = self.dfs(node.right)

        self.res = max(self.res, left + right)

        return 1 + max(left, right)