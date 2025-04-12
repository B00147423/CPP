#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int longestConsecutiveSequence(const vector<int>& nums) {
    if (nums.empty()) {
        cout << "The input vector is empty. Returning 0." << endl;
        return 0;
    }

    unordered_set<int> mySet(nums.begin(), nums.end());
    cout << "Initial set: {";
    for (int num : mySet) {
        cout << num << " ";
    }
    cout << "}" << endl;

    int longestStreak = 0;

    for (int num : mySet) {
        cout << "Processing number: " << num << endl;

        // Check if it's the start of a sequence
        bool isStartOfSequence = (mySet.find(num - 1) == mySet.end());
        cout << "Checking if " << num << " - 1 = " << num - 1 << " is in the set: "
             << (isStartOfSequence ? "No (start of a new sequence)" : "Yes (part of an existing sequence)") << endl;

        if (isStartOfSequence) {
            int currentNum = num;
            int currentStreak = 1;

            // Count consecutive numbers
            while (mySet.find(currentNum + 1) != mySet.end()) {
                currentNum += 1;
                currentStreak += 1;
                cout << "Found next number in sequence: " << currentNum << " (current streak: " << currentStreak << ")" << endl;
            }

            longestStreak = max(longestStreak, currentStreak);
            cout << "Longest streak updated to: " << longestStreak << endl;
        }
    }

    cout << "Final longest streak: " << longestStreak << endl;
    return longestStreak;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Input vector: {100, 4, 200, 1, 3, 2}" << endl;
    int result = longestConsecutiveSequence(nums);
    cout << "Longest consecutive sequence length: " << result << endl;
    return 0;
}
