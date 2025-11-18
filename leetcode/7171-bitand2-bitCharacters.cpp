#include <vector>
class Solution {
public:
    bool isOneBitCharacter(std::vector<int>& bits) {
        
        int left = 0;
        int right = bits.size()-1;

        while (left < right) {
            if (bits[left] == 1){
                left += 2;
            }
            else{
                left+=1;
            }
        }
        return left == right;
    }
};