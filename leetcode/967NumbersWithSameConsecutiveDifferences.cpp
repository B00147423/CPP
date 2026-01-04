#include <vector>
using namespace std;

class Solution {
    vector<int> nums;
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for (int d = 1; d <= 9; d++) {
            backtrack(n, k, 1, d);
        }
        return nums;
    }

    void backtrack(int n, int k, int length, int current){
        if (length == n) {
            nums.push_back(current);
            return;
        }


        int last = current % 10;

        int next1 = last + k;

        if (next1 <= 9) {
            backtrack(n, k, length + 1, current * 10 + next1);
        }

        int next2 = last - k;
        if (k != 0 && next2 >= 0) {
            backtrack(n, k, length + 1, current * 10 + next2);
        }

    }
};