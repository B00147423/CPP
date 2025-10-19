#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        
        int pos1 = -1, pos2 = -1;
        int distance  = INT_MAX;

        for(int i = 0; i < wordsDict.size(); i++)
        {
            if (wordsDict[i] == word1) 
                pos1 = i;
            if (wordsDict[i] == word2) 
                pos2 = i;
            if(pos1 != -1 && pos2 !=-1)
                distance = min(distance, abs(pos1 - pos2));
        }
        return distance;
    }
};