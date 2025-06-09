
#include <vector>
#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while(l <= r){
            int k = (l+r) /2;
        
            long long totalTime = 0;

            for(int p : piles){
                totalTime += ceil(static_cast<double>(p) / k);
                
                
                cout << "\n "<< totalTime;
            }

            if(totalTime <= h){
                res = k;
                r = k - 1;
            }else{
                l = k +1;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    int result = solution.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl; // Output should be 4
    return 0;
}
