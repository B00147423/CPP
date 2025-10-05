#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {


    unordered_map<string, deque<string>> adj;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //buidl adj lsit 
        for(auto& t: tickets){
            string from = t[0];
            string to = t[1];
            adj[from].push_back(to);
        }

        for(auto& [from, to] : adj){
            sort(to.rbegin(), to.rend());
        }

        vector<string> res;
        dfs("JFK", adj, res);
        reverse(res.begin(), res.end());
        return res;
    }

private:
    void dfs(const string& src, unordered_map<string, deque<string>>& adj, vector<string>& res) {

        while(!adj[src].empty()){
            string dst = adj[src].back();
            adj[src].pop_back();
            dfs(dst, adj, res);
        }
        res.push_back(src);

    }
};



int main() {
    // example flight tickets: [from, to]
    vector<vector<string>> tickets = {
        {"HOU", "JFK"},
        {"SEA", "JFK"},
        {"JFK", "SEA"},
        {"JFK", "HOU"}
    };

    Solution s;

    // findItinerary returns a vector<string>, not a number
    vector<string> result = s.findItinerary(tickets);

    // print result itinerary
    for (auto& city : result) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}
