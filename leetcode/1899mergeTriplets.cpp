#include <vector>
class Solution {
public:
    bool mergeTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
        // If there are no triplets, we can’t form anything → return false
        if (triplets.size() == 0) return false;

        // Variables to keep track of the maximum values seen so far
        // for each of the 3 positions (columns)
        int max0 = 0, max1 = 0, max2 = 0;

        // Loop through every triplet in the input
        for (auto &t : triplets) {
            // Extract each value from the current triplet
            int x = t[0];
            int y = t[1];
            int z = t[2];

            // Only consider triplets that don't exceed the target values
            if (x <= target[0] && y <= target[1] && z <= target[2]) {
                // Update the running maximums for each position
                max0 = std::max(max0, x);
                max1 = std::max(max1, y);
                max2 = std::max(max2, z);
            }
        }

        // Return true only if our maximums exactly match the target values
        // NOTE: there's a typo here — last comparison should be max2 == target[2]
        return max0 == target[0] && max1 == target[1] && max2 == target[1];
    }
};
