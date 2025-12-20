#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];

            while (!st.empty() && st.top() > 0 && curr < 0) {
                if (abs(st.top()) < abs(curr)) {
                    st.pop();
                    continue;
                } 
                else if (abs(st.top()) == abs(curr)) {
                    st.pop();
                    curr = 0;
                    break;
                } 
                else {
                    curr = 0;
                    break;
                }
            }
            if (curr != 0) {
                st.push(curr);
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};