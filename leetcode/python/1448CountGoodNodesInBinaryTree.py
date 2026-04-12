# 1448. Count Good Nodes in Binary Tree
# Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        res = 0

        def dfs(node, maxVal):
            nonlocal res
            if not node:
                return

            if node.val >= maxVal:
                res += 1

            maxVal = max(maxVal, node.val)

            dfs(node.left, maxVal)
            dfs(node.right, maxVal)

        dfs(root, root.val)
        return res