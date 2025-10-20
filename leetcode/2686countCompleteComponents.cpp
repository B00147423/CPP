#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        
        for(const auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

       
        int res = 0;

        for(int node = 0; node < n; node++){
            if(!visit[node]){
                vector<int> component;
                dfs(adj, visit, node, component);
                int k = component.size();
                int edgeCount = 0;

                for (int u : component) {
                    edgeCount += adj[u].size();
                }
                edgeCount /= 2; // each edge counted twice
  
                if(edgeCount == k*(k-1)/2)
                res++;
            }

        }
        return res;
    }

  void dfs(vector<vector<int>>& adj, vector<bool>& visit, int node, vector<int>& comp) {
        visit[node] = true;
        comp.push_back(node);
        for (int nei : adj[node]) {
            if (!visit[nei]) {
                dfs(adj, visit, nei, comp);
            }
        }
    }
};