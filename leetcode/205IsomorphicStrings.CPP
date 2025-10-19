#include <string>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        
        char map_s[256] = {0};  // s[i] ↦ t[i]
        char map_t[256] = {0};  // t[i] ↦ s[i]
        
        for (int i = 0; i < s.size(); i++) {
       
            if ((map_s[s[i]]) && (map_s[s[i]] != t[i])) return false;
            if ((map_t[t[i]]) && (map_t[t[i]] != s[i])) return false;
            
            map_s[s[i]] = t[i];
            map_t[t[i]] = s[i];
        }
        return true;
    }
};