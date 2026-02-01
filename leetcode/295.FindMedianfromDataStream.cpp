// 295. Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/
#include <vector>
#include <algorithm>
using namespace std;
class MedianFinder {
    vector<int> v;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto it = lower_bound(v.begin(), v.end(), num);
        v.insert(it, num);
    }
    
    double findMedian() {
        int n = v.size();

        if(n % 2 == 1){
            int medianValue = n / 2;
            return v[medianValue];
        }else{
           int leftIndex = (n / 2)-1;
           int rightIndex = n / 2;

           double leftValue = v[leftIndex];
           double rightValue = v[rightIndex];

           double sum = leftValue + rightValue;
           double medianValue = sum /2;
           
           return medianValue;
        }
    }
};

/*
dry run :: 

medianfind er object
addNum(1)
v = []
it = lower_bound([],1) -> it = v.begin()
insert at it -> v = [1]
addNum 2

v = [1]
it = lower_bound([1],2) -> it = v.end() 
insert at it -> v = [1,2]

then 1,2,3 then 1,2,4 etc etc

thsiis tim,e complexity is O(n) for insertion as we are inserting in vector
and O(1) for finding median as we are accessing by index

find median is we calculate what is middle index and return value at that index

findMedian() called
v = [1,2,3,4,5]
n = 5
left = 2 right =2
return v[2] = 3 median is 3

findMedian() called
v = [1,2,3,4]
n = 4
left = 1 right =2
leftValue = v[1] = 2
rightValue = v[2] = 3
sum = 5
median = 5/2 = 2.5


------------------------
not sorted vector case
findMedian() called
v = [1,3,4,2]
n = [4]
left =1 right =2
leftValue = v[1] = 3
rightValue = v[2] = 4
sum = 7
median = 7/2 = 3.5
but this i wrong as vector is not sorted here
*/


/*

functionality, stress, boundary, error, security, localization, performance tests

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */