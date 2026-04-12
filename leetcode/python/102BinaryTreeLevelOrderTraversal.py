# 102. Binary Tree Level Order Traversal
# Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []

        def levelOrderDFS(node, depth):
            if not node:
                return None
            
            if len(res) == depth:
                res.append([])
            res[depth].append(node.val)
            levelOrderDFS(node.left, depth+1)
            levelOrderDFS(node.right, depth+1)
        
        levelOrderDFS(root, 0)
        return res
