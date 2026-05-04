#Leetcode : 212. Word Search II
from typing import List


class Solution:

    class TrieNode:
        def __init__(self):
            self.children = {}
            self.word = None

    def buildTrie(self, words):
        root = self.TrieNode()

        for word in words:
            node = root
            for ch in word:
                if ch not in node.children:
                    node.children[ch] = self.TrieNode()
                node = node.children[ch]
            node.word = word
        return root

    def dfs(self, r, c, node, board, res, ROWS, COLS):
        if r < 0 or c < 0 or r >= ROWS or c >= COLS:
            return

        ch = board[r][c]

        if ch == "#" or ch not in node.children:
            return

        node = node.children[ch]

        if node.word:
            res.append(node.word)
            node.word = None

        board[r][c] = "#"

        self.dfs(r + 1, c, node, board, res, ROWS, COLS)
        self.dfs(r - 1, c, node, board, res, ROWS, COLS)
        self.dfs(r, c + 1, node, board, res, ROWS, COLS)
        self.dfs(r, c - 1, node, board, res, ROWS, COLS)

        board[r][c] = ch


    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        ROWS, COLS = len(board), len(board[0])
        res = []
        root = self.TrieNode()


        for r in range(ROWS):
            for c in range(COLS):
                self.dfs(r, c, root, board, res, ROWS, COLS)

        return res