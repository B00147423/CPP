
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size()-1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if(nums[left] <= target && target < nums[mid]){
                    right = mid-1; // searchig nelf tpart
                }else{
                    left = mid+1; // searhcing right part,
                }
            }else{
                //right half is aorted
                if(nums[mid] < target && target <= nums[right] ){
                    left = mid + 1; // searhcing right part,
                } else{
                    right = mid - 1;// / go LEFT
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nms = {4,5,6,7,0,1,2};
    int target = 0;
    cout << s.search(nms, target) << endl; // Output: 4
    return 0;
}