#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
class Solution{

public:

    void backtrack(int start, std::vector<int>& nums, std::vector<std::vector<int>>& res, std::vector<int>& stack) {
        res.push_back(stack);
        for(std::size_t i = start; i < nums.size(); i++){
            
            stack.push_back(nums[i]);
            backtrack(i+1, nums, res, stack);
            stack.pop_back();
        }
    }
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> stack;
        backtrack(0, nums, res, stack);
        return res;
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> result = s.subsets(nums);


    std::cout << "Subsets:" << std::endl;
    for (const auto& subset : result) {
        std::cout << "[";
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}