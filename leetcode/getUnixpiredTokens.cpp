#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;
vector<int> getUnexpiredTokens(int tiem_toLIve, vector<string> queries){

    unordered_map<string, int> tokensGenerated;
    vector<int> result;

  
    for(int i = 0; i < queries.size(); i++){
      stringstream ss(queries[i]);
        string action, token;
        int time;
        ss >> action >> token >> time;
    }

}

