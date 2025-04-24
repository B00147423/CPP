#include <iostream>
#include <unordered_map>
using namespace std;
#include <stack>
#include <vector>
#include <algorithm>
class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
    
            unordered_map<char, int> s1dict;
            unordered_map<char, int> s2dict;
    
            if (s1.length() > s2.length()){
                return false;
            }
    
            for (int i = 0; i < s1.length(); i++) {
                s1dict[s1[i]]++;
                s2dict[s2[i]]++;
            
                std::cout << "s1[" << i << "] = " << s1[i] << std::endl;
                std::cout << "s2[" << i << "] = " << s2[i] << std::endl;
                std::cout << "------------------------" << std::endl;
            }
            if (s1dict == s2dict) {
            return true;
            }
    
            int left = 0;
            for (std::string::size_type right = s1.size(); right < s2.size(); right++){
                s2dict[s2[right]]++;
                s2dict[s2[left]]--;
                std::cout << "s2[" << right << "] = " << s2[right] << std::endl;
                std::cout << "s2[" << left << "] = " << s2[left] << std::endl;
                    
                if (s2dict[s2[left]] == 0){
                s2dict.erase(s2[left]);
                }
                left++;
                    
                if (s2dict == s1dict){
                return true;
                }
            }
        return false;    
        }
    };

    int main(){
        Solution s;
        string s1 = "ab";
        string s2 = "eiddbaooo";
        cout << s.checkInclusion(s1, s2) << endl; // Output: 1 (true)
        return 0;
    }