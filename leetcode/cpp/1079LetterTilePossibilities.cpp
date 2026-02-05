#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numTilePossibilities(std::string tiles) {
        vector<int> freq(26, 0);

        for (char c : tiles) {
            freq[c - 'A']++;
        }
        return backtrack(freq);
    }

    int backtrack(vector<int>& freq) {
        int count = 0;

        for (int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            
            freq[i]--;
            count++;
            count+= backtrack(freq);
            freq[i]++;
        }
        return count;
    }
    
};