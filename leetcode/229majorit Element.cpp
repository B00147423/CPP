#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>


using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        vector<int> result;

        unordered_map<int, int> freq;


        for(auto& num: nums){
            freq[num]++; 

        }
        int threshHold = nums.size() / 3;

        for(auto& p : freq){
            if(p.second > threshHold){
                result.push_back(p.first);
            }
        }

        return result; 
    }

};