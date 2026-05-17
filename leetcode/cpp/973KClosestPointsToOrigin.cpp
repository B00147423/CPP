// 973. K Closest Points to Origin
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {


        priority_queue<pair<int,int>> pq; // {dist, index}
        for (int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];

            int dist = x * x + y * y;
            pq.push({dist, i});

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>> result;
        while(!pq.empty()){
            int index = pq.top().second;
            pq.pop();
            result.push_back(points[index]);
        }

        return result;


    }
};


int main(){

    // Example usage
    Solution sol;
    vector<vector<int>> points = {{1, 3}, {-2, 2},
                                    {5, 8}, {0, 1}};     
    int k = 2;
    vector<vector<int>> closestPoints = sol.kClosest(points, k);
    for (const auto& point : closestPoints) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;
    return 0;

}
/*
return k closest point to the 0, 0

to get closes point we need to do  Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

*/