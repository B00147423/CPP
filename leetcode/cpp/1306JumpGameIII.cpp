// Leetcode 1306. Jump Game III
//Link: https://leetcode.com/problems/jump-game-iii/description/
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        vector<bool> visited(arr.size(), false);

        q.push(start);

        visited[start] = true;


        while(!q.empty()){
            int i = q.front();
            q.pop();
            if (arr[i] == 0) return true;
            int left = i - arr[i];
            int right = i + arr[i];
            
            if(left >= 0 && !visited[left]){
                visited[left] = true;
                q.push(left);
            }

            if(right < arr.size() && !visited[right]){
                visited[right] = true;
                q.push(right);
            }
        }
        return false;
    }
};

/*

arr = 4,2,3,0,3,1,2]
index 5 -> index 4 -> index 1 -> index 3 
1          3           2              
jump once to idnex 4 
jump = 1
jump to iudnedx 3 with jump of 3
we resch jump idx 1 with jump val 2,

jukp to then idx 3 whic hwould make it indx 3 whic hhas val 0












*/