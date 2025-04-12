#include <iostream>
#include <unordered_set>
#include <vector>


using namespace std;


vector<int> removeDuplicates(const vector<int>& myList) {
    
     unordered_set<int> uniqueSet;
     std::vector<int> result;
     for(const auto& i : myList){
         if(uniqueSet.find(i) == uniqueSet.end()){
            uniqueSet.insert(i);
            result.push_back(i);
         }
     }
     
    return result;
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function removes duplicate integers from a   |
    //   |   given vector 'myList'.                            |
    //   | - It uses an unordered_set for quick look-up and    |
    //   |   elimination of duplicates.                        |
    //   | - Returns a vector of unique integers.              |
    //   |                                                     |
    //   | Return type: vector<int>                            |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'uniqueSet' stores unique numbers from 'myList'.  |
    //   | - Use 'begin()' and 'end()' to copy elements back   |
    //   |   to a vector.                                      |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
}




std::vector<int> removeDuplicates(const std::vector<int>& myList) {
    // Create an unordered_set from the vector, which automatically removes duplicates
    std::unordered_set<int> uniqueSet(myList.begin(), myList.end());
    
    // Convert the unordered_set back into a vector
    return std::vector<int>(uniqueSet.begin(), uniqueSet.end());
}