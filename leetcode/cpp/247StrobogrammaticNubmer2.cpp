#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<string> result;
    vector<pair<char,char>> pairs = {
        {'0','0'},
        {'1','1'},
        {'6','9'},
        {'8','8'},
        {'9','6'}
    };
public:
    vector<string> findStrobogrammatic(int n) {
        string cur(n, ' ');
        backtrack(cur, 0, n-1);
        return result;
    }
private:
    void backtrack(string& cur, int l, int r){
        if(l > r)  {
            result.push_back(cur);
            return;
        }

        for(auto& p : pairs){
            char a = p.first;
            char b = p.second;
        //NO 0S START or
            if(l == 0 && a == '0' && cur.size() > 1){
                continue;
            }
        //middle
            if(l == r && a != b){
                continue;
            }
            cur[l] = b;
            cur[r] = a;
            
            backtrack(cur, l+1, r-1);
        }    
    }
};
