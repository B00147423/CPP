#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;
class AuthenticationManager {
        unordered_map<string, int> expiry;
        int time_to_live;
public:
    AuthenticationManager(int timeToLive) {
        time_to_live = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        expiry[tokenId] = currentTime + time_to_live;
    }
    
    void renew(string tokenId, int currentTime) {
        if(expiry.count(tokenId) && expiry[tokenId] > currentTime)
        {
            expiry[tokenId] = currentTime + time_to_live;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(auto& p : expiry){
            if(p.second  > currentTime){
                count++;
            }
        }
        return count;
    }
};

int main(){
    AuthenticationManager auth(300);  // Initialize with a timeToLive value of 300 seconds
}
