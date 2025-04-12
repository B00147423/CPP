#include <iostream>

void modifyValue(int& val){ // Non-const reference: Allows modification
    val = 20;
}

void printValue(const int& val){ // Const reference: No modification
    std::  cout << "Value: " << val << std::endl;
}

int main(){
    int x = 10;

    // Modifying value using non-const reference
    modifyValue(x);

    std::cout <<"Modified x Passed by reference: " << x << std::endl;
    // Printing value using const reference
    printValue(x);

    return 0;
}