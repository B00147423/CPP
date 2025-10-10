#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        // sort by start index
        sort(offers.begin(), offers.end());

        int m = offers.size();
        vector<int> maxValueFromIndex(m + 1, 0);

        // fill from the back
        for (int i = m - 1; i >= 0; i--) {
            maxValueFromIndex[i] = max(maxValueFromIndex[i + 1], offers[i][2]);
        }

        int maxSum = 0;

        // loop through each offer
        for (int i = 0; i < m; i++) {
            int currentValue = offers[i][2];

            // binary search for first offer that starts after offers[i][1]
            int left = i + 1, right = m;
            while (left < right) {
                int mid = (left + right) / 2;
                if (offers[mid][0] > offers[i][1])
                    right = mid;
                else
                    left = mid + 1;
            }

            // if there is a non-overlapping offer, add its best profit
            if (left < m)
                currentValue += maxValueFromIndex[left];

            maxSum = max(maxSum, currentValue);
        }

        return maxSum;
    }
};
