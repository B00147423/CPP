//Leetcode 2402. Meeting Rooms III
//Link: https://leetcode.com/problems/meeting-rooms-iii/description/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> freeRooms;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busyRooms;

        vector<int> count(n, 0);

        for (int i = 0; i < n; i++) {
            freeRooms.push(i);
        }

        sort(meetings.begin(), meetings.end());

 
        for (auto& m : meetings) {
            //[[0,10],[1,5],[2,7],[3,4]]
            long long start = m[0];//start[[0,
            long long end = m[1];//end  10]
            long long duration = end - start;//10
            //busyRooms.top().first == //10
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();

                count[room]++;
                busyRooms.push({end, room});
            } 
            else {
                auto [endTime, room] = busyRooms.top();
                busyRooms.pop();

                count[room]++;

                busyRooms.push({endTime + duration, room});
            }
        }


        int res = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[res]) {
                res = i;
            }
        }

        return res;
    }
};


/*

meetings[i] = [starti, endi] 

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
*/