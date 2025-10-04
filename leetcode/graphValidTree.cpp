        /*
                         0 
                       / | \
                      1  2  3
                      |
                      4
              

              0,1
              1,4
             no more child after 4 backtrack to 0

              0,2

              no more child after 2 backtrack to 0

              0, 3 

              no more child after 4 backtrack to 0

            we successfuly traversed throug hthe tree
            the pairs didnt duploicted meanign it is a valdi tree

        */  


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() < n-1){
            return false;
        }

        vector<vector<int>> adj(n);

        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visit;

          if (!dfs(0, -1, visit, adj)) {
            return false;
        }


        return visit.size() == n;
    }


private:
    bool dfs(int node, int parent, unordered_set<int>& visit,
             vector<vector<int>>& adj) {
        if (visit.count(node)) {
            return false;
        }

        visit.insert(node);
        for (int nei : adj[node]) {
            if (nei == parent) {
                continue;
            }
            if (!dfs(nei, node, visit, adj)) {
                return false;
            }
        }
        return true;
    }
};