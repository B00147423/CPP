#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        
        string res;
        stack<int> st;
        int num = 1;


        for(int i = 0; i < pattern.size(); i++){
            st.push(num++);
            if(pattern[i] == 'I'){
                while(!st.empty()){
                    res+= char('0'+st.top());
                    st.pop();
                }
            }   
        }

        st.push(num);
        while (!st.empty()) {
            res += char('0' + st.top());
            st.pop();
        }  
        return res;
    }
};