#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<string> result;
public:
    vector<string> letterCasePermutation(string s) {
        backtrack(s, 0);
        return result;
    }

    void backtrack(string s, int i){
        if(i == s.size()){
            result.push_back(s);
            return;
        }

        if (isalpha(s[i])) 
        {
            char original = s[i];

            s[i] = tolower(original);
            backtrack(s, i+1);

            s[i] = toupper(original);
            backtrack(s, i+1);
        }else{
            backtrack(s, i + 1);
        
        }
    }
};