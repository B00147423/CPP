#include <vector>
#include <queue>
#include <array>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> available;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pending;

        int n = tasks.size();
        for (int i = 0; i < n; ++i) {
            pending.push({tasks[i][0], tasks[i][1], i});
        }

        vector<int> res;
        long long time = 0;
        while (!pending.empty() || !available.empty()) {
            while (!pending.empty() && pending.top()[0] <= time) {
                auto [enqueueTime, processTime, index] = pending.top();
                pending.pop();
                available.push({processTime, index});
            }

            if (available.empty()) {
                time = pending.top()[0];
                continue;
            }

            auto [processTime, index] = available.top();
            available.pop();
            time += processTime;
            res.push_back(index);
        }

        return res;
    }
};