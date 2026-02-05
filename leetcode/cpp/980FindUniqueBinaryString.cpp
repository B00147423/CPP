#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    unordered_set<string> seen;
    int n;
    string result = "";
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        n = nums.size();
        for (auto& s : nums) seen.insert(s);

        string curr = "";
        dfs(curr);
        return result;
    }

    void dfs(string& curr) {

        if(!result.empty()) return;

        if (curr.size() == n) {
            if (!seen.count(curr)) {
                result = curr;
            }
            return;
        }

        curr.push_back('0');
        dfs(curr);
        curr.pop_back();
        
        curr.push_back('1');
        dfs(curr);
        curr.pop_back();
    }
};