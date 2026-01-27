//26. Remove Duplicates from Sorted Array
//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int k = 0;  // index of last unique element

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[k]) {
                ++k;
                nums[k] = nums[i];
            }
        }

       nums.resize(k + 1);
       return k + 1;
    }
};