#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    vector<int> stones = {2, 3, 6, 2, 4};
    priority_queue<int> pq(stones.begin(), stones.end());

    // print what we get by popping (always sorted descending)
    cout << "Pop sequence: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}
