
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // Main function: returns the edge that forms a cycle in the graph
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // number of nodes (edges.size() == n for a tree + 1 edge)
        int n = edges.size();

        // adjacency list for the graph
        vector<vector<int>> adj(n + 1);

        // go through each edge and add it one by one
        for (const auto& edge : edges) {
            // current edge nodes
            int u = edge[0];
            int v = edge[1];

            // add the connection both ways (undirected)
            adj[u].push_back(v);
            adj[v].push_back(u);

            // create a new visited array for DFS
            vector<bool> visit(n + 1, false);

            // check if adding this edge creates a cycle
            if (dfs(u, -1, adj, visit)) {
                // return the edge that caused the cycle
                return {u, v};
            }
        }

        // no redundant edge found
        return {};
    }

private:
    // depth-first search to check if a cycle exists
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visit) {
        // if this node is already visited, a cycle is detected
        if (visit[node])
            return true;

        // mark the node as visited
        visit[node] = true;

        // check all neighbors
        for (int nei : adj[node]) {
            // skip the parent node (don’t go back where we came from)
            if (nei == parent)
                continue;

            // if a recursive DFS call finds a cycle, return true
            if (dfs(nei, node, adj, visit))
                return true;
        }

        // if no cycles found in any branch
        return false;
    }
};
