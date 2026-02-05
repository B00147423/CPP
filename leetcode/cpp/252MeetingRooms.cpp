#include <string>
#include <vector>
#include <queue>
#include <algorithm>


class Solution {
public:
    bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
        
        /*
            intervals = [[0,30],[5,10],[15,20]]              
            start = 0;
            end = 30
            nextStart
        */


        if (intervals.size() <= 1) return true;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size()-1; i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int nextStart = intervals[i+1][0];

            if (end > nextStart) {
                return false;
            }
        }
        return true;
    }
};