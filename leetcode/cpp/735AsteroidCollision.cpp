#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];

            while (!st.empty() && st.back() > 0 && curr < 0) {
                 if (abs(st.back()) < abs(curr)) {
                    st.pop_back();
                    continue;
                } 
                else if (abs(st.back()) == abs(curr)) {
                    st.pop_back();
                    curr = 0;
                    break;
                } 
                else {
                    curr = 0;
                    break;
                }
            }
            if (curr != 0) {
                st.push_back(curr);
            }
        }

        return st;
    }
};