#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
#include <unordered_set>

class Solution {
    unordered_map<int, vector<int>> preMap;

    unordered_set<int> visiting;
    unordered_set<int> visited;

    vector<int> result;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {}; // make sure every course is in the map
        }
        for (auto &p : prerequisites) {
            preMap[p[1]].push_back(p[0]);
        }

        // run dfs for each course
        for (int crs = 0; crs < numCourses; crs++) {
            if (!dfs(crs)) return {}; // cycle found -> empty result
        }

        // reverse because dfs builds in postorder
        std::reverse(result.begin(), result.end());
        return result;
    }


    bool dfs(int crs){
        if (visiting.count(crs)) return false; // cycle
        if (visited.count(crs)) return true;   // already processed


        visiting.insert(crs);

        for (int pre : preMap[crs]){
            if(!dfs(pre))return false;
        }

        visiting.erase(crs);
        visited.insert(crs);
        result.push_back(crs);

    return true;
    }
};