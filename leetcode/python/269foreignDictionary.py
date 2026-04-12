# 269. Alien Dictionary
# Link: https://leetcode.com/problems/alien-dictionary/
from collections import defaultdict
from typing import List

class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        adj = {}
        #ADJ LIST
        for w in words:
            for c in w:
                adj[c] = set()

        for i in range(len(words) - 1):
            word1 = words[i]
            word2 = words[i + 1]
            minLen = min(len(word1), len(word2))
            if len(word1) > len(word2) and word1[:minLen] == word2[:minLen]:
                return ""
            for j in range(minLen):
                if word1[j] != word2[j]:
                    adj[word1[j]].add(word2[j])
                    break
            
        visited = {}

        res = []

        def dfs(char):
            if char in visited:
                return visited[char]

            visited[char] = True

            for neighbor in adj[char]:
                if dfs(neighbor):
                    return True

            visited[char] = False
            res.append(char)
        
        for char in adj:
            if dfs(char):
                return ""
        res.reverse()
        return "".join(res)
    
'''
FULL DFS TRACE (NO STEPS SKIPPED)

Code:

def dfs(char):
if char in visited:
return visited[char]

```
visited[char] = True

for neighChar in adj[char]:
    if dfs(neighChar):
        return True

visited[char] = False
res.append(char)
```

---

Graph:
h -> e -> r -> n -> f

Initial:
visited = {}
res = []

---

Call dfs('h')

1. dfs('h'):
   if 'h' in visited? NO

   visited['h'] = True
   visited = {h: True}

   for neighChar in adj['h']:
   neighChar = 'e'

   ```
   call dfs('e')
   ```

---

2. dfs('e'):
   if 'e' in visited? NO

   visited['e'] = True
   visited = {h: True, e: True}

   for neighChar in adj['e']:
   neighChar = 'r'

   ```
   call dfs('r')
   ```

---

3. dfs('r'):
   if 'r' in visited? NO

   visited['r'] = True
   visited = {h: True, e: True, r: True}

   for neighChar in adj['r']:
   neighChar = 'n'

   ```
   call dfs('n')
   ```

---

4. dfs('n'):
   if 'n' in visited? NO

   visited['n'] = True
   visited = {h: True, e: True, r: True, n: True}

   for neighChar in adj['n']:
   neighChar = 'f'

   ```
   call dfs('f')
   ```

---

5. dfs('f'):
   if 'f' in visited? NO

   visited['f'] = True
   visited = {h: True, e: True, r: True, n: True, f: True}

   for neighChar in adj['f']:
   (no neighbors → loop skipped)

   visited['f'] = False
   res.append('f')

   res = [f]

   return None (no cycle)

---

Back to dfs('n'):

if dfs('f') returned True? NO

loop finished

visited['n'] = False
res.append('n')

res = [f, n]

return None

---

Back to dfs('r'):

if dfs('n') returned True? NO

loop finished

visited['r'] = False
res.append('r')

res = [f, n, r]

return None

---

Back to dfs('e'):

if dfs('r') returned True? NO

loop finished

visited['e'] = False
res.append('e')

res = [f, n, r, e]

return None

---

Back to dfs('h'):

if dfs('e') returned True? NO

loop finished

visited['h'] = False
res.append('h')

res = [f, n, r, e, h]

return None

---

FINAL:

res = [f, n, r, e, h]

reverse → h e r n f

---

CYCLE CHECK:

if char in visited:
return visited[char]

* True  → cycle
* False → already processed


'''