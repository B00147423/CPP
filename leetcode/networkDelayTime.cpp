#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // adjacency list: from node → [(to node, travel time)]
        unordered_map<int, vector<pair<int, int>>> edges;

        // build the adjacency list from input
        for (auto& t : times) {
            // first value = start node
            int from = t.front();

            // second value = destination node
            int to = t[1];

            // last value = travel time
            int cost = t.back();

            // store (destination, time) in list for this start node
            edges[from].emplace_back(to, cost);
        }

        // min-heap (priority queue) storing (total time so far, node)
        // 'greater<>' makes it a min-heap (smallest time pops first)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        // push starting node with time = 0
        minHeap.push({0, k});

        // track visited nodes
        unordered_set<int> visited;

        // store the latest time reached so far
        int t = 0;

        // process nodes while heap isn't empty
        while (!minHeap.empty()) {
            // get the node with the smallest total time
            auto [currTime, node] = minHeap.top();
            minHeap.pop();

            // skip if node already processed
            if (visited.count(node)) continue;

            // mark node as visited
            visited.insert(node);

            // update current total time
            t = currTime;

            // explore all neighbors of this node
            for (auto& [next, travel] : edges[node]) {
                // only push unvisited nodes
                if (!visited.count(next)) {
                    // push neighbor with new total time
                    minHeap.push({currTime + travel, next});
                }
            }
        }

        // if we reached all nodes, return total time; otherwise, -1
        return visited.size() == n ? t : -1;
    }
};

int main() {
    // example edges: [from, to, time]
    vector<vector<int>> times = {
        {1,2,1},
        {2,3,1},
        {1,4,4},
        {3,4,1}
    };

    // total nodes and start node
    int n = 4, k = 1;

    // run the solution
    Solution s;
    cout << s.networkDelayTime(times, n, k) << endl; // expected output: 3
}
