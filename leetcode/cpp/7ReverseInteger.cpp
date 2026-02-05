#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0; 
        // stores the reversed number as it is being built

        while (x != 0) { 
        // loop until all digits of x are processed

            int pop = x % 10; 
            // take the last digit of x (can be negative if x < 0)

            cout << "anPOP = " << pop << endl;
            // debug output: shows the digit just extracted

            x /= 10; 
            // remove the last digit from x

            cout << "\nINT_MAX / 10 = " << (INT_MAX / 10);
            // debug output: shows the safe upper boundary before multiplying by 10

            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            // overflow check for positive numbers:
            // if multiplying rev by 10 (and adding pop) would exceed INT_MAX

            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;
            // overflow check for negative numbers:
            // if multiplying rev by 10 (and adding pop) would go below INT_MIN

            rev = rev * 10 + pop;
            // shift current reversed number left by one digit
            // then append the new digit
        }

        return rev;
        // return the fully reversed integer
    }
};
