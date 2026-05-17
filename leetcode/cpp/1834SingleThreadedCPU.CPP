// Leetcode 1834. Single-Threaded CPU
//Link: https://leetcode.com/problems/single-threaded-cpu/description/
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> res;
        vector<vector<int>> sortedTasks;

        int originalIndex = 0;

        for (auto& it : tasks) {
            int enqueueTime = it[0];
            int processingTime = it[1];

            sortedTasks.push_back({enqueueTime, processingTime, originalIndex});

            originalIndex++;
        }
        
        sort(sortedTasks.begin(), sortedTasks.end());    

        
        long long currentTime = 0;
        int i = 0;

        while (i < sortedTasks.size() || !pq.empty()) {

            if (pq.empty() && currentTime < sortedTasks[i][0]) {
                currentTime = sortedTasks[i][0];
            }

            while (i < sortedTasks.size() && sortedTasks[i][0] <= currentTime) {
                int time = sortedTasks[i][1];
                int index = sortedTasks[i][2];

                pq.push({time, index});
                i++;
            }

            auto top = pq.top();
            pq.pop();

            int processingTime = top.first;
            int originalIndex = top.second;

            res.push_back(originalIndex);
            currentTime += processingTime;
        }
    return res;
    }
};

/*
n tasks 

0 n -1

2d int ar tasks,

tasks[i] = [entqueTimei processingTimei] ith task will be available to process at enqueuetime[i]
    and wil ltake profcessingTime[i]

    single threaded cpu 

    if cpu idle no available task to prcoess cpi remains idle, 

    if cpu idle and therer are taks vailable, thje cpi will chose shrotest processing time.

    if multiple tasks have same shrotest processing time, chose tasks with smallest index

    once task starts to process, cpu will process entire task no stopping.

    if task finishs, start a new one


*/