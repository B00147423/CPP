#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    int res = 0;

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        // build adjacency list
        for (auto& e : edges) {
            int a = e[0];
            int b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(0, -1, adj, values, k);
        return res;
    } 

private:

    long long dfs(int node, int parent, vector<vector<int>>& adj,
                  vector<int>& values, int k) {

        long long curSum = values[node];
        std::cout << "\ncursum : " << curSum << endl;
        for (int nei : adj[node]) {
            if (nei == parent) continue;
            curSum += dfs(nei, node, adj, values, k);
        }

        if (curSum % k == 0) {
            res++;
            return 0;  
        }

        return curSum;
    }
};