#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {

        // sort intervals by start value
        sort(intervals.begin(), intervals.end());

        // set prevEnd to the end of the first interval
        int prevEnd = intervals[0][1];

        // counter for removed intervals
        int res = 0;

        // loop from the second interval onward
        for (int i = 1; i < intervals.size(); i++) {

            // get current interval's start
            int start = intervals[i][0];

            // get current interval's end
            int end   = intervals[i][1];

            // check if current start is far enough
            if (start >= prevEnd) {

                // update prevEnd to current end
                prevEnd = end;

            } else {

                // increase removal counter
                res++;

                // update prevEnd to the smaller end
                prevEnd = std::min(prevEnd, end);
            }
        }

        // return how many intervals were removed
        return res;
    }
};
