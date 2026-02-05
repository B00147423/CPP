#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
        Input: height = [1,8,6,2,5,4,8,3,7]
        left = 0;
        right =  loop widnow
        we need to sum u


        */

        int left = 0; 
        int right = height.size() - 1;
        int maxArea = 0;
        int area = 0;
        while(left < right){
            area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
      return maxArea;
    }
};

/*
Time Complexity: O(n) — each element is visited at most once by the two pointers.
Space Complexity: O(1) — only a few integer variables used, no extra data structures.
*/