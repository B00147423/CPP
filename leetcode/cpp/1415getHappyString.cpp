#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<string> res;
public:
    string getHappyString(int n, int k) {

        string cur;

        dfs(cur, n);

        if(k > res.size()) return "";   

        return res[k-1];
    }

    void dfs(string& cur, int n){
        //base case
        if(cur.size() == n){
            res.push_back(cur);
            return;
        }


        for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {

            //if cur is not emtpy check if the last character palces is the same
            if(!cur.empty() && cur.back() == currentChar) continue;
            cur.push_back(currentChar);
            dfs(cur, n);
            cur.pop_back();
        }
    }
};