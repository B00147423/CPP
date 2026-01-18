#include <vector>
#include <unordered_map>



class Solution {
public:
    std::vector<int> getSneakyNumbers(std::vector<int>& nums) {

        std::unordered_map<int, int> frequency;

        for(int n : nums){
            frequency[n]++;
        }
        std::vector<int> result;
        for(auto& [n, count] : frequency){
            if(count > 1){
                result.push_back(n);
            }
        }
        return result;
    }
};

/*

Time Complexity: O(N)
You iterate through the input array once to build the frequency map → O(N)
Then you iterate through the frequency map (which has at most N unique elements) to build the result → O(N)
Total: O(N) + O(N) = O(N)


Space Complexity: O(N)
The hash map can store up to N elements in the worst case, and the result array can also grow up to N.
Therefore, the space complexity is O(N).



*/