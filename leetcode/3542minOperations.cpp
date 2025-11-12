#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        return dfs(nums , 0, nums.size()-1);
    }

private:
    int dfs(std::vector<int> & nums, int l, int r)
    {
        if (l > r) return 0;
        int minVal = INT_MAX;

        for(int i = l; i <= r; i++)
            minVal = std::min(minVal, nums[i]);

        int res = minVal;

        for(int i =l; i <= r; i++)
            nums[i] -= minVal; // turns into a 0 

        int i = l;
        while (i <= r)
        {
            while(i <= r && nums[i] == 0)i++;
            if(l > r) break;
            int j = i;
            while(j <= r && nums[j] != 0)j++;
            res += dfs(nums, i, j-1);
            i = j;
            
        }
        return std::min(res ,r-l+1);
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {3, 1, 2, 1};
    int result = solution.minOperations(nums);
    std::cout << "Result: " << result << std::endl;
}