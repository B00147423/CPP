// LeetCode Problem 42: Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        int left_max = 0;
        int right_max = 0;

        while(left < right){
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    ans += left_max - height[left];
                }
                ++left;
            }else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    ans += right_max - height[right];
                }
                --right;
            }
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

/*
This solution uses a two-pointer approach to calculate the amount of trapped rain water.
dry run:
height = [0,1,0,2,1,0,1,3,2,1,2,1]
left | right | left_max | right_max | height[left] | height[right] | ans
-----------------------------------------------------------
    0   |  11   |    0     |     0      |      0       |       1       |  0
    1   |  11   |    1     |     0      |      1       |       1       |  0
    1   |  10   |    1     |     1      |      1       |       2       |  0
    2   |  10   |    1     |     2      |      0       |       2       |  1
    3   |  10   |    2     |     2      |      2       |       2       |  1
    3   |  9    |    2     |     2      |      2       |       1       |  2
    4   |  9    |    2     |     2      |      1       |       1       |  3
    5   |  9    |    2     |     2      |      0       |       1       |  5
    6   |  9    |    2     |     2      |      1       |       1       |  5
    7   |  9    |    3     |     2      |      3       |       1       |  5
    7   | 8     |    3     |     2      |      3       |       2       | 5
    End:  
return ans = 6

[0,1,0,2,1,0,1,3,2,1,2,1]

init:
left=0 right=11 left_max=0 right_max=0 ans=0

loop 1:
height[left]=0 < height[right]=1
0 >= 0 → left_max=0
left=1

loop 2:
height[left]=1 < 1 ✘
1 >= 0 → right_max=1
right=10

loop 3:
height[left]=1 < 2
1 >= 0 → left_max=1
left=2

loop 4:
height[left]=0 < 2
0 < 1 → ans += 1-0 = 1 (ans=1)
left=3

loop 5:
height[left]=2 < 2 ✘
2 >= 1 → right_max=2
right=9

loop 6:
height[left]=2 < 1 ✘
1 < 2 → ans += 2-1 = 1 (ans=2)
right=8

loop 7:
height[left]=2 < 2 ✘
2 >= 2 → right_max=2
right=7

loop 8:
height[left]=2 < 3
2 >= 1 → left_max=2
left=4

loop 9:
height[left]=1 < 3
1 < 2 → ans += 2-1 = 1 (ans=3)
left=5

loop 10:
height[left]=0 < 3
0 < 2 → ans += 2-0 = 2 (ans=5)
left=6

loop 11:
height[left]=1 < 3
1 < 2 → ans += 2-1 = 1 (ans=6)
left=7

stop (left == right)

return ans = 6

*/
