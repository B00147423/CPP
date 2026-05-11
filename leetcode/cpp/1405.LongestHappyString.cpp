// Leetcdode: 1405 Longest Happy String 
// link: https://leetcode.com/problems/longest-happy-string/description/
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string s = "";
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int count = top.first;
            char current_char = top.second;

            int stringLength = s.size();
            int lastChar = s.back();
            int secondLastChar  =  s[stringLength - 2];

            if (stringLength >= 2 && lastChar == current_char && secondLastChar == current_char) {
                if (pq.empty()) break;

                auto second = pq.top();
                pq.pop();

                s.push_back(second.second);
                second.first--;

                if (second.first > 0) {
                    pq.push(second);
                }
                pq.push(top);
            }else {
                s.push_back(current_char);
                count--;
                if (count > 0) {
                    pq.push({count, current_char});
                
                }
            }
        }
        return s;
    }
};