#include <string>
using namespace std;

class Solution {
public:
    bool splitString(string s) {
        int n = s.size();

        for(int i = 1; i < n; i++){
            long long first = stoll(s.substr(0, i));
            if(dfs(s, i, first)){
                return true;
            }
        }
        return false;
    }

    bool dfs(string& s, int index, long long prev){
        if(index == s.size()){
            return true;
        }
        long long num = 0;
        for (int i = index; i < s.size(); i++){
        /*
        s = "345"
            index = 0
            num = 3 * 10 + 4 = 34
        */
  
            num = num * 10 + (s[i] - '0');
            if(num == prev-1){
                if(dfs(s, i+1, num)) return true;
            }

            if(num >=prev) break;
        }
        return false;
    }
};