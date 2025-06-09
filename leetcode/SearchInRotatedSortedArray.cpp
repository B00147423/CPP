
#include <vector>
#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while (l <= r){
            int mid = (l + r) / 2;
            
            if (target == nums[mid]) {
                return mid;
            }

            if(nums[l] <= nums[mid]){
                if(target > nums[mid] || target < nums[l]){
                    l= mid+1;
                }else{
                    r = mid-1;
                }
            }else{
                if(target < nums[mid] || target > nums[r]){
                    r = mid-1;
                }else{
                    l= mid+1;
                }
            }
        }
        return -1;

    }
};

int main() {
    Solution solution;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = solution.search(nums, target);
    cout << "Index of target in rotated sorted array: " << result << endl; // Output should be 4
    return 0;
}


/*

🚀 Each loop:

    Check which side is sorted (nums[l] <= nums[mid])

    Use the sorted side’s boundaries to check if target is inside

    If yes → search that side

    If not → search the other side

    Next loop: same process — one half will always be sorted again
*/