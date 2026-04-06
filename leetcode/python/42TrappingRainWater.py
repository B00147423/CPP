
# leetcode 42. Trapping Rain Water
from typing import List
class Solution:
    def trap(self, height: List[int]) -> int:
        l, r = 0, len(height)-1
        left_max, right_max = 0, 0

        water = 0

        while l < r:
            if height[l] < height[r]:
                if height[l] >= left_max:
                    left_max = height[l]
                else:
                    water += left_max - height[l]
                l += 1
            else:
                if height[r] >= right_max:
                    right_max = height[r]
                else:
                    water += right_max - height[r]
                r -=1
        return water

'''
height = [0,1,0,2,1,0,1,3,2,1,2,1]

l = 0, r = 11
left_max = 0, right_max = 0
water = 0


Step 1:
height[l]=0, height[r]=1 → process left
0 >= 0 → left_max = 0
l = 1

Step 2:
height[l]=1, height[r]=1 → process right
1 >= 0 → right_max = 1
r = 10

Step 3:
height[l]=1, height[r]=2 → process left
1 >= 0 → left_max = 1
l = 2

Step 4:
height[l]=0, height[r]=2 → process left
0 < 1 → water += 1
water = 1
l = 3

Step 5:
height[l]=2, height[r]=2 → process right
2 >= 1 → right_max = 2
r = 9

Step 6:
height[l]=2, height[r]=1 → process right
1 < 2 → water += 1
water = 2
r = 8

Step 7:
height[l]=2, height[r]=2 → process right
2 >= 2 → right_max = 2
r = 7

Step 8:
height[l]=2, height[r]=3 → process left
2 >= 1 → left_max = 2
l = 4

Step 9:
height[l]=1, height[r]=3 → process left
1 < 2 → water += 1
water = 3
l = 5

Step 10:
height[l]=0, height[r]=3 → process left
0 < 2 → water += 2
water = 5
l = 6

Step 11:
height[l]=1, height[r]=3 → process left
1 < 2 → water += 1
water = 6
l = 7


Stop: l == r

Final water = 6
'''