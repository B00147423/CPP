//767. Reorganize String
//link: https://leetcode.com/problems/reorganize-string/description/
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        if (s.empty()) return "";
        
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> freq;


        for(int c : s){
            freq[c]++;
        }

        for(auto it : freq){
            pq.push({it.second, it.first});
        }
        string res = "";
        while(pq.size() > 1){
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();
            res += top1.second;
            res += top2.second;

            top1.first--;
            top2.first--;

            if(top1.first > 0) pq.push(top1);
            if(top2.first > 0) pq.push(top2);
        }
        if (!pq.empty()) {
            if (pq.top().first > 1) return "";
            res += pq.top().second;
        }
        return res;
    }
};