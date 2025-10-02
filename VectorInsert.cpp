
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    map<int, string> m;
    unordered_map<int, string> um;

    m[7] = "dog";
    m[12] = "cat";
    m[3] = "fish";

    um[7] = "dog";
    um[12] = "cat";
    um[3] = "fish";

    cout << "map output (ordered):\n";
    for (auto &p : m) {
        cout << p.first << " -> " << p.second << "\n";
    }

    cout << "\nunordered_map output (un-ordered):\n";
    for (auto &p : um) {
        cout << p.first << " -> " << p.second << "\n";
    }
}
