#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count frequency of each task
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }

        // Step 2: Push frequencies into a max-heap
        priority_queue<int> maxHeap;
        for (int cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        // Step 3: Time counter + cooldown queue
        int time = 0;
        queue<pair<int, int>> cooldown; 
        // cooldown stores {remaining_count, time_when_it_can_be_used}

        // Step 4: Process tasks
        while (!maxHeap.empty() || !cooldown.empty()) {
            time++; // one unit of time passes

            if (!maxHeap.empty()) {
                int cnt = maxHeap.top() - 1; // run one task
                maxHeap.pop();

                if (cnt > 0) {
                    // put task into cooldown
                    cooldown.push({cnt, time + n});
                }
            }

            // if the front task in cooldown is ready, push it back into maxHeap
            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<char> tasks1 = {'A','A','A','B','B','B'};
    int n1 = 2;
    cout << "Example 1 -> tasks: {A,A,A,B,B,B}, n=2" << endl;
    cout << "Least interval needed: " 
         << solution.leastInterval(tasks1, n1) << endl << endl;

    // Example 2
    vector<char> tasks2 = {'A','A','A','A'};
    int n2 = 3;
    cout << "Example 2 -> tasks: {A,A,A,A}, n=3" << endl;
    cout << "Least interval needed: " 
         << solution.leastInterval(tasks2, n2) << endl << endl;

    // Example 3
    vector<char> tasks3 = {'A','B','C','A','B','C'};
    int n3 = 2;
    cout << "Example 3 -> tasks: {A,B,C,A,B,C}, n=2" << endl;
    cout << "Least interval needed: " 
         << solution.leastInterval(tasks3, n3) << endl << endl;

    return 0;
}
