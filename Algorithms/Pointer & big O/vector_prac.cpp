#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> myVector = {10, 20, 25, 6, 7, 2, 27, 1};
  myVector.erase(myVector.begin());

  for(int i = 0; i < myVector.size(); i++) {
    cout << myVector[i] << " ";
  }
  cout << endl;

  cout << "after erasing: ";
    // Erasing the first element
    myVector.erase(myVector.begin());

    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i] << " ";
    }
  cout << endl;

  return 0;
}
