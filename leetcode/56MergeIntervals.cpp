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