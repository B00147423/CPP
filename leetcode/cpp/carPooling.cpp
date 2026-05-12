
// 1094. Car Pooling 
// https://leetcode.com/problems/car-pooling/description/
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        for (auto& trip : trips) {
            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            pq.push({from, passengers});   // pickup
            pq.push({to, -passengers});    // dropoff
        }

        int current = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            current += top.second;

            if (current > capacity) {
                return false;
            }
        }

        return true;
    }
};
