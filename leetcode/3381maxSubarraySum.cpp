#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefixSum = 0, maxSum = LLONG_MIN;
        vector<long long> kSum(k, LLONG_MAX / 2);

        kSum[k - 1] = 0;

        for(int i = 0; i < n; i++){
            prefixSum += nums[i];
            cout << "\nprefixSum = " << prefixSum << endl;
            cout << "\nkSum[i % k]) = " << kSum[i % k] << endl;
            maxSum = max(maxSum, prefixSum - kSum[i % k]);
            cout << "\nmaxSum = " << maxSum << endl;
            kSum[i % k] = min(kSum[i % k], prefixSum);
        }
        return maxSum;
    }
};