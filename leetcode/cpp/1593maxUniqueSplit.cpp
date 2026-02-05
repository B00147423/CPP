#include <unordered_set>
#include <string>
using namespace std;

class Solution {
    unordered_set<string> used;
    int best = 0;

public:
    int maxUniqueSplit(string s) {
        backtrack(s, 0);
        return best;
    }

    void backtrack(const string& s, int index) {
        if (index == s.size()) {
            best = max(best, (int)used.size());
            return;
        }

        for (int i = index; i < s.size(); i++) {
            string part = s.substr(index, i - index + 1);
            if (used.count(part)) continue;

            used.insert(part);
            backtrack(s, i + 1);
            used.erase(part);
        }
    }
};