#include <iostream>
#include <string>
using namespace std;

int main() {
    string word1 = "a";
    string word2 = "b";

    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {

            if (i == 0)
                cout << "i=" << i << " j=" << j << "  (i==0)\n";
            else if (j == 0)
                cout << "i=" << i << " j=" << j << "  (j==0)\n";
            else if (word1[i-1] == word2[j-1])
                cout << "i=" << i << " j=" << j << "  compared word1[" << i-1 << "] and word2[" << j-1 << "]\n";
            else
                cout << "i=" << i << " j=" << j << "  compared word1[" << i-1 << "] and word2[" << j-1 << "]\n";
        }
    }
}
