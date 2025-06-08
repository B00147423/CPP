#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
// This code implements a solution to the "Car Fleet" problem on LeetCode.
class Solution {

public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        /*
        /(target - POSITION) / SPEED = for calculating the tiem it takes to reach target
        */    

        int n = position.size();

        vector<pair<int, int>> pair;
  
        for(int i = 0; i < n; i ++){
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        vector<double> stack;

        for (auto& p : pair) {
            stack.push_back((double)(target - p.first) / p.second);
            if (stack.size() >= 2 &&

                stack.back() <= stack[stack.size() - 2])
            {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};


int main() {
    Solution solution;
    vector<int> position = {10, 20, 30};
    vector<int> speed = {2, 3, 4};
    int target = 100;

    int fleets = solution.carFleet(target, position, speed);
    cout << "Number of car fleets: " << fleets << endl;

    return 0;
}   