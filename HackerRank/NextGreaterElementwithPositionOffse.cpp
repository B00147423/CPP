#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

/*
 * Complete the 'findNextGreaterElementsWithDistance' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY readings as parameter.
 */

vector<vector<int>> findNextGreaterElementsWithDistance(vector<int> readings) {
    
    
    int n = readings.size();
    vector<vector<int >> result(n, vector<int>(2, -1));
    
    
    stack<int> st;
    
    for(int i = 0; i < n; i++){
        while(!st.empty()  && readings[i] > readings[st.top()])
        {
            int index = st.top();
            st.pop();
            result[index][0] = readings[i]; // next greater
            result[index][1] = i-index; //distance
        }
        st.push(i);
    }
    return result;
    
}
