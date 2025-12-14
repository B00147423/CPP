#include <vector>
#include <iostream>
class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        int m = *max_element(people.begin(), people.end());
        std::vector<int> count(m + 1, 0);
        for (int p : people) {
            count[p]++;
        }


        int idx = 0, i = 0;
        while(idx < people.size()){
            while(count[i] == 0){
                i++;
            }
            people[idx++] =i;
            count[i]--;
        }

        int result = 0, l = 0, r = people.size() - 1;

        while(l <= r){
            int remain = limit - people[r--];
            std::cout << "remain : " <<  remain;
            result++;

            if(l <= r && remain >= people[l]){
                l++;
            }
        }
        return result;
    }
};