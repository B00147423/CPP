
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> seen;
        for (int candy : candyType){
            seen.insert(candy);
        }
        int uniqueCandySize = seen.size();
        int candyTypesSize = candyType.size();
        int result = min(uniqueCandySize, candyTypesSize / 2);
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> candyType = {1, 1, 2, 2, 3, 3};
    int result = sol.distributeCandies(candyType);
    cout << result << endl;
}