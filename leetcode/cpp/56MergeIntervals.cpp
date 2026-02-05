#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int rows = intervals.size();
        for (int i = 0; i < rows; i++) {
            int start = intervals[i][0];
            int end   = intervals[i][1];

            while (i + 1 < rows && intervals[i + 1][0] <= end) {
                end = max(end, intervals[i + 1][1]);
                i++;
            }

            result.push_back({start, end});
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // sort intervals by first element
        sort(intervals.begin(), intervals.end());

        // create output list
        vector<vector<int>> output;

        // put the first interval into output
        output.push_back(intervals[0]);

        // go through each interval
        for (auto& interval : intervals) {

            // get current interval's start
            int start = interval[0];

            // get current interval's end
            int end = interval[1];

            // get the last interval's end inside output
            int lastEnd = output.back()[1];

            // check if start is small enough to update last end
            if (start <= lastEnd) {

                // replace the last interval's end with the bigger one
                output.back()[1] = max(lastEnd, end);

            } else {

                // add a new interval to output
                output.push_back({start, end});
            }
        }

        // return output list
        return output;
    }
};