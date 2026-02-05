#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<vector<string>> parts;
        vector<string> current;
        backtrack(s, 0, current, parts);

        vector<string> result;
        for(auto & ip : parts){

            result.push_back(ip[0]+ "." + ip[1] + "." + ip[2] + "." + ip[3]);
        }
        return result;
    }
private:
    void backtrack(string& s, int index, vector<string>& current, vector<vector<string>>& parts){



        //base case
        if(current.size() == 4 && index == s.size()){
            parts.push_back(current);
            return;
        }

        if(current.size() == 4){
            return;
        }


        for(int len = 1; len <= 4 && len + index <=s.size(); len++){
           string segment = s.substr(index, len);
            //no leading 0s
           if(segment.size() > 1 && segment[0] == '0') break;
            // value <= 255
           if(stoi(segment) > 255) continue;

            current.push_back(segment);
            backtrack(s, index+len, current, parts);
            current.pop_back();
        }
    }
};           