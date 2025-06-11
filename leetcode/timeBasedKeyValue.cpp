
using namespace std;
#include <unordered_map>
#include <vector>
#include <string>
#include <utility> // for std::pair
#include <iostream>
//     Time complexity: O(log n) for each get operation
// Time complexity: O(1) for set operation, where n is the number of key-value pairs for a specific key
//     Space complexity: O(m*n) for storing the key-value pairs
//
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> keyStore;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timeStamp) {
        auto& values = keyStore[key];
        string result = "";
        int left = 0, right = values.size()-1;
        while(left <= right){
            int mid = (left+right) / 2;
            if(values[mid].first <= timeStamp){
                result = values[mid].second;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return result;
    }
};

int main(){
    TimeMap timeMap;
    timeMap.get("Alice", 1); // returns ""
    timeMap.set("Alice", "Happy", 1); // set key "Alice" with value "Happy" at timestamp 1
    timeMap.get("Alice", 1); // returns "Happy"
    timeMap.set("Alice", "Sad", 2); // set key "Alice" with value "Sad" at timestamp 2
    timeMap.get("Alice", 2); // returns "Sad"
    cout << timeMap.get("Alice", 3) << endl; // returns "Sad" since it is the last value before timestamp 3
    cout << timeMap.get("Alice", 0) << endl; // returns "" since no value is set before timestamp 1

}