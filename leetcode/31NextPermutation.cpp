#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();


        //finding the pivot point to
        int pivot = -1;
        for(int i = n-2; i >=  0; i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }
        // we didnt find pivot because it doesnt exitst
        // reverse the array
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // find the element from the right that
        // is greater than pivot    
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Reverse the elements from pivot + 1 to the 
        // end to get the next permutation
        reverse(nums.begin()+ pivot+1, nums.end());
    }
};

/*
arr = [1, 2, 3]
n   = 3

FIRST LOOP (find pivot)
----------------------
i = 1        arr[1] < arr[2]     2 < 3     true
pivot = 1

SECOND LOOP (find swap)
----------------------
i = 2        arr[2] > arr[1]     3 > 2     true
swap(2, 1)

arr = [1, 3, 2]

REVERSE SUFFIX
--------------
start = pivot + 1 = 2
end   = 2

(no change)

FINAL
-----
[1, 3, 2]
*/