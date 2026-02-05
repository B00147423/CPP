#include <string>
class Solution {
public:
    int maxOperations(std::string s) {
        int n = s.size();
        int count = 0,res =0;

        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                count++;
            }
            if(s[i] == '1' && s[i+1] == '0'){
                res += count;
            }
        }
        return res;
    }
};