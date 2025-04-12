#include <iostream>
using namespace std;
// Non-const reference: Allows modification
void modifyValue(int& val) {  
    val = 20;
}
// Const reference: No modification
void printValue(const int& val) {  
    cout << "Value: " << val << endl;
}

int main() {
    int x = 10;
    
    // Modifying value using non-const reference
    modifyValue(x);
    cout << "Modified x: " << x << endl;

    // Printing value using const reference
    printValue(x);

    // Uncommenting the next line will give an error because `val` in printValue is const
    // modifyValue(printValue(x)); 

    return 0;
}
