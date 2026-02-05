#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        vector<int> combinations;
        backtrack(1, n, k, combinations);
        return result;
    }

    void backtrack(int start, int n, int k, vector<int>& combinations){
        if(combinations.size() == k)
        {
            result.push_back(combinations);
            return;
        }

        for(int i = start; i <= n; i++){
            combinations.push_back(i);
            backtrack(i+1, n, k, combinations);
            combinations.pop_back();
        }
    }
};