// 2558. Take Gifts From the Richest Pile
// https://leetcode.com/problems/take-gifts-from-the-richest-pile/
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        

        priority_queue<int> pq;


        for(long long i = 0; i < gifts.size(); i++){
            pq.push(gifts[i]);
        }
        
        while (k > 0) {
            int top_Elem = pq.top(); pq.pop();

            int reduced = sqrt(top_Elem);
            pq.push(reduced);
            k--;
        }
        
        long long sum = 0;


        while (!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }

        return sum;
    }
};