#include <vector>
class Solution {
public:
    // Rotates the array nums to the right by k steps
    void rotate(std::vector<int>& nums, int k) {
        
        // n = number of elements in the array
        int n = nums.size();

        // Create a temporary array of the same size
        std::vector<int> temp(n);

        // Loop over every index in the original array
        for (int i = 0; i < n; i++) {

            // Place nums[i] into its rotated position
            // i + k moves it k steps to the right
            // % n wraps the index back into 0..n-1 if it goes past the end
            temp[(i + k) % n] = nums[i];
        }

        // Copy the rotated result back into nums
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};
