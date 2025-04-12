#include <iostream>
#include "vector"
class LargeObject{
    public:
        std::vector<int> data;
    LargeObject(){
        // Simulating a large object
        data.resize(10000, 42);
    }
};

// Passing by value (copying the entire object
void passByValue(LargeObject obj){
     std::cout << "Passed by value, data size: " << obj.data.size() << std::endl;
}
// Passing by reference (no copy, original object passed)
void passByReference(LargeObject& obj){
    std::cout << "Passed by const reference, data size:" << obj.data.size() << std::endl;
}
// Passing by const reference (no copy, object cannot be modified)
void passByConstReference(const LargeObject& obj){
    std::cout << "Passed by const reference, data size: " << obj.data.size() << std::endl;
}
int main(){
    LargeObject obj;

    // Demonstrating passing by value
    passByValue(obj);  // Copying the object

    // Demonstrating passing by reference
    passByReference(obj);  // No copying, direct reference

    // Demonstrating passing by const reference
    passByConstReference(obj);  // No copying, object can't be modified

    return 0;

}

