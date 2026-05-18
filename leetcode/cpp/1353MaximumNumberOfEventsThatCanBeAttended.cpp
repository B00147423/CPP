//Leetcode: 1353. Maximum Number of Events That Can Be Attended
//Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 0;
        int day = 0;
        int res = 0;


            // Iterate through each day until we have processed all events and attended all possible events
         while (i < events.size() || !pq.empty()) {
            // If there are no events in the priority queue, set the current day to the start day of the next event
            if (pq.empty()) {
                day = events[i][0];
            }
            // Add all events that start today
            while (i < events.size() && events[i][0] <= day) {
                pq.push(events[i][1]);
                i++;
            }
            // Remove events whose lastDay is before today
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            // Attend the event that ends the earliest (the one at the top of the priority queue)
            if (!pq.empty()) {
                pq.pop();
                res++;
                day++;
            }
        }
        return res;
    }
};


