
#include <vector>
#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findMin(vector<int> &nums) {


        int l = 0, r = nums.size() - 1;
     
        while(l < r){
            int mid = (l + r) / 2;
            cout <<"\n" << mid;
            if(nums[mid] < nums[r]){
                r = mid;
            }else {
                l = mid + 1;
            }

        }
        return nums[l];
    }
};



int main() {
    Solution solution;
    vector<int> nums = {3, 4, 5, 1, 2};
    int result = solution.findMin(nums);
    cout << "Minimum in rotated sorted array: " << result << endl; // Output should be 1
    return 0;
}