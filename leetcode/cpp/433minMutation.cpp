
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(endGene)) return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        string genes = "ACGT";

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            string currGene = front.first;
            int steps = front.second;

            if (currGene == endGene) return steps;

            for (int i = 0; i < currGene.size(); i++) {
                char original = currGene[i];

                for (char g : genes) {
                    if (g == original) continue;

                    currGene[i] = g;

                    if (dict.count(currGene)) {
                        q.push({currGene, steps + 1});
                        dict.erase(currGene); // mark visited
                    }
                }

                currGene[i] = original;
            }
        }

        return -1;
    }
};;