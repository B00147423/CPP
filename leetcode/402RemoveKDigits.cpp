#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(char c : num){
            while(!st.empty() && k > 0 && st.back() > c){
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        while(k > 0 && !st.empty())
        {
            st.pop_back();
            k--;
        }

        while(!st.empty() && st.front() == '0')
        {
            st.erase(st.begin());
        }

        if(st.empty() )return "0";
        return st;
                
    }
};

int main(){
    Solution sol;

    cout << sol.removeKdigits("1432219", 3);  // expected: "1219"
    cout << sol.removeKdigits("10200", 1);    // expected: "200"
    cout << sol.removeKdigits("10", 2);       // expected: "0"
    cout << sol.removeKdigits("9", 1);        // expected: "0"
    cout << sol.removeKdigits("12345", 2);    // expected: "123"

}