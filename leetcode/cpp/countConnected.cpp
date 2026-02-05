/*You give the program how many nodes there are (n) and which pairs of nodes are connected (edges).

It builds a map (the adjacency list) that says who each node is directly connected to.

For your input [[0,1], [1,2], [2,3], [4,5]] that map looks like:

0 → [1]
1 → [0,2]
2 → [1,3]
3 → [2]
4 → [5]
5 → [4]


It also makes a list called “visited” to remember which nodes it has already checked.

Then it goes through every node one by one:

If the node has already been visited, it skips it.

If it hasn’t been visited, that means it’s part of a new connected group.
It runs a process (DFS) starting from that node.

The DFS process does this:

Mark the starting node as visited (true).

Look at all the nodes that are directly connected to it.

For each connected node that hasn’t been visited yet, run DFS again on that one.

So, for your data:

It starts with node 0 → visits 0,1,2,3.
Now all of those are marked true.

When the main loop later reaches node 4, it’s still false.
That means this is a new group.
DFS(4) marks 4 true, looks at its neighbour list [5], goes to 5, marks 5 true.
Now both 4 and 5 are done.

When the loop finishes, every node is marked visited.
The counter (res) was increased twice:

once for the 0-1-2-3 group

once for the 4-5 group

That’s why the result is 2 connected components.*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {

    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);

        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for(int node = 0; node < n; node++){
            if(!visit[node]){
                dfs(adj, visit, node);
                res++;
            }
        }
        return res;
        
    }
private:
    void dfs(const vector<vector<int>>& adj, vector<bool>& visit, int node) {
        visit[node] = true;
        for (int nei : adj[node]) {
            if (!visit[nei]) {
                dfs(adj, visit, nei);
            }
        }
    }
};
