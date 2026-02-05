#include <vector>
#include <string>
#include <stack>
class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {
        std::stack<int> st;
        int sum = 0;
        int result = 0;
        for(int i = 0; i < operations.size(); i++)
        {
            if (operations[i] != "+" && operations[i] != "C" && operations[i] != "D") {
                st.push(std::stoi(operations[i]));
            }
            
            if(operations[i] == "+" && !st.empty()){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                sum = a + b;
                st.push(b);
                st.push(a);
                st.push(sum);
            }
            if(operations[i] == "C" && !st.empty()){
                st.pop();
            }
            if(operations[i] == "D" && !st.empty()){
                st.push(st.top() * 2);
            }
        }
        
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};