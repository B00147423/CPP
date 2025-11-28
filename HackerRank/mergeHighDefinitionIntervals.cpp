/*
n an array of intervals [startTime, endTime], merge all overlapping intervals and return a sorted array of non-overlapping intervals.

Example

Input
    intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]

Output
    [[1, 6], [8, 10], [15, 18]]

Explanation

    - Step 1: Sort intervals by start time (already sorted). 
    - Step 2: Initialize merged list with first interval [1,3]. 
    - Step 3: Compare [2,6] with last merged [1,3]. They overlap (2 ≤ 3), so merge into [1,6]. Step 4: Compare [8,10] with last merged [1,6]. No overlap (8 > 6), append [8,10]. 
    - Step 5: Compare [15,18] with last merged [8,10]. No overlap (15 > 10), append [15,18]. 

Result: [[1,6],[8,10],[15,18]].


Input Format

    The first line contains an integer denoting the number of intervals.
    The second line contains an integer denoting the length of individual interval array.
    Each of the next N lines contains two space-separated integers startTime and endTime
    Intervals may be provided in any order; duplicates and fully contained intervals are allowed.

Example
    4
    2
    1 3
    2 6
    8 10

Constraints
    0 <= intervals.length <= 100000
    intervals[i].length == 2 for all 0 <= i < intervals.length
    0 <= intervals[i][0] < intervals[i][1] <= 10^9 for all 0 <= i < intervals.length
    
Output Format
    Return a 2D array of two space-separated integers start and end, 
    representing the merged intervals sorted by increasing start time.
*/



/*
 * Complete the 'mergeHighDefinitionIntervals' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY intervals as parameter.
 */
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;


vector<vector<int>> mergeHighDefinitionIntervals(vector<vector<int>> intervals) {
    //base case empty
    if (intervals.empty()) {
        return {};
    }
    
    vector<vector<int>> merged;
    

    // Sort intervals by start time
    sort(intervals.begin(), intervals.end());
    merged.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        vector<int>& last = merged.back();
        vector<int>& current = intervals[i];
        
        // Check if current interval overlaps with last merged interval
        if (current[0] <= last[1]) {
            // Merge intervals by updating the end time
            last[1] = max(last[1], current[1]);
        } else {
            // No overlap, add as new interval
            merged.push_back(current);
        }
    }
    
    return merged;
}