#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[1] != b[1]){
                    return a[1] < b[1];
                } else{
                    return a[0] > b[0];
                }
               
            }
        );

        int s1 = -1;
        int s2 = -1;
        int res = 0;

        for(auto& interval : intervals){
            int left = interval[0];// `1
            int right = interval[1]; // 3

            if (left <= s1 && s2 <= right ) //  if left 1 <= -1. and -1 <= 3 false
                continue;

            if(left <= s2){ //1 <= -2 false
                res += 1;
                cout <<"\ns1 : " << s1;
                s1 = s2;
                cout <<"\ns1 : " << s1;
                s2 = right;
                cout <<"\ns2 : " << s2;
            } 
            else{
                res +=2;// res += 2 res = 2 s1 = right-1;  
                s1 = right-1; // right = 3 so right becoems 2, so s1 becoemns 2
                s2 = right; // s2 becoems right which is 3
            }

            // we get s1 = 2 s2 = 3
        }
        return res;
    }
};