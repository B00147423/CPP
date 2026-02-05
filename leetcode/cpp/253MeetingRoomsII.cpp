#include <string>
#include <vector>
#include <queue>
#include <algorithm>


class Solution {
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
        
        std::sort(intervals.begin(), intervals.end());
            std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
            for (const auto& interval : intervals) {
                if (!minHeap.empty() && minHeap.top() <= interval[0]) {
                    minHeap.pop();
                }
                minHeap.push(interval[1]);
            }
        return minHeap.size();
    }
};

//NEETCODE VERSION 


 //Definition of Interval:
 class Interval {
 public:
     int start, end;
     Interval(int start, int end) {
         this->start = start;
         this->end = end;
     }


// --------------------------NEETCODE VERSION----------------------------------------
public:
    int minMeetingRooms(std::vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(),
            [](const Interval& a, const Interval& b){
                return a.start < b.start;
            });
            std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
            for (const auto& interval : intervals) {
                if (!minHeap.empty() && minHeap.top() <= interval.start) {
                    minHeap.pop();
                }
                minHeap.push(interval.end);
            }
        return minHeap.size();
    }
};
