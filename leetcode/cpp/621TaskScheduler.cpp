//621. Task Scheduler
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty()) return 0;

        unordered_map<char, int> freq;
        priority_queue<int> pq;

        for (char task : tasks) {
            freq[task]++;
        }

        for (auto it : freq) {
            pq.push(it.second);
        }

        int time = 0;

        while(pq.size() > 1)
        {
            vector<int> temp;
            int cycle = n + 1;

            while (cycle > 0 && !pq.empty()) {
                int count = pq.top();
                pq.pop();

                count--;
                time++;
                cycle--;

                if (count > 0) {
                    temp.push_back(count);
                }
            }
        
            for (int count : temp) 
            {
                pq.push(count);
            }

            if(!pq.empty())
            {
                time += cycle;//idle slots
            }
        }

        return time;
    }
};

/*


*/