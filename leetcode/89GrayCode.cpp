#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    vector<int> result;
    unordered_set<int> visited;

public:
    vector<int> grayCode(int n) {
        int total = 1 << n;       // total = 2^n numbers
        result.push_back(0);
        visited.insert(0);

        backtrack(0, n, total);

        return result;
    }


    
    bool backtrack(int num, int n, int total) {
        if (result.size() == total)
            return true;

        for (int bit = 0; bit < n; bit++) {
            int nxt = num ^ (1 << bit);  // flip 1 bit of num

            if (!visited.count(nxt)) {
                visited.insert(nxt);
                result.push_back(nxt);

                if (backtrack(nxt, n, total))
                    return true;

                visited.erase(nxt);
                result.pop_back();
                
            }
        }
        return false;
    }
};