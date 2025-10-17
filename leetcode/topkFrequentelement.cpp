
using namespace std;
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        vector<pair<int, int>> freqList;
        for (auto& p : count) {
            freqList.push_back({p.second, p.first});
        }
        
        sort(freqList.rbegin(), freqList.rend());
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqList[i].second);
        }
        return result;
    }
};