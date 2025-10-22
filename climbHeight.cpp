#include <iostream>
using namespace std;

/*
 * Complete the 'jumps' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER flagHeight
 *  2. INTEGER bigJump
 */

int jumps(int flagHeight, int bigJump) {
    int bigCount = flagHeight / bigJump;   // how many big jumps we can take
    int remainder = flagHeight % bigJump; // what's left
    return bigCount + remainder;          // total jumps = big + 1-unit jumps
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int flagHeight, bigJump;
    cin >> flagHeight >> bigJump;

    int result = jumps(flagHeight, bigJump);
    cout << result << "\n";

    return 0;
}
