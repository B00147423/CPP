#include <iostream>
using namespace std;

class reverseInt {
public:
  int reverse(int x) {
    int remainder = 0;
    while (x != 0) {
      remainder = remainder * 10 + x % 10;
      x /= 10;
    }
    return remainder;
  }
};

int main() {
  reverseInt sol;
  int num = -12345;
  int reversedNum = sol.reverse(num);
  cout << "Original number: " << num << endl;
  cout << "Reversed number: " << reversedNum << endl;

  return 0;
}
