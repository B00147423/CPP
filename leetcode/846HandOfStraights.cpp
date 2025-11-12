#include <vector>
#include <unordered_map>
#include <algorithm>


class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        // if total cards can't be evenly divided into groups, it's impossible
        if (hand.size() % groupSize != 0) return false;

        // sort the hand so we process numbers in ascending order
        std::sort(hand.begin(), hand.end());

        // create a hash map to count how many of each card value we have
        std::unordered_map<int, int> freq;

        // build the frequency map
        for (int n : hand) freq[n]++;

        // go through each card (smallest to largest)
        for (int n : hand) {
            // if we've already used all copies of this card, skip it
            if (freq[n] == 0) continue;

            // try to form a group starting from this card
            for (int i = 0; i < groupSize; i++) {
                // check if the next consecutive card (n+i) exists
                if (freq[n + i] == 0) return false;

                // use one copy of that card
                freq[n + i]--;
            }
        }

        // if we built all groups successfully, return true
        return true;
    }
};
