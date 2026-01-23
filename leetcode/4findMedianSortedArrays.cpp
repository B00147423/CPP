// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> merged;

        //merged first.
        for(int i = 0; i < nums1.size(); i++){
            merged.push_back(nums1[i]);
        }

        for(int i = 0; i < nums2.size(); i++){
            merged.push_back(nums2[i]);
        }
        //sort merged
        sort(merged.begin(), merged.end());


        int m = merged.size();
        if(m % 2 == 1){
             return merged[m / 2];
        }else{
            return (merged[m / 2-1] + merged[m/2]) / 2.0;
        }

    }
};