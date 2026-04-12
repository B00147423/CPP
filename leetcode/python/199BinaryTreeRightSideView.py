# 199. Binary Tree Right Side View
# Link: https://leetcode.com/problems/binary-tree-right-side-view/
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        def dfs(node, depth):
            if not node:
                return None
            
            if depth == len(res):
                res.append(node.val)

            dfs(node.right, depth+1)
            dfs(node.left, depth+1)
        dfs(root, 0)
        return res