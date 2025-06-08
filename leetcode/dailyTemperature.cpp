#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0);

    for (int i = n - 2; i >= 0; i--) {
        int j = i + 1;
        while (j < n && temperatures[j] <= temperatures[i]) {
            if (res[j] == 0) {
                j = n;
                break;
            }
            j += res[j]; // Skip ahead using precomputed steps
        }
        if (j < n) {
            res[i] = j - i; // Store number of days to wait
        }
    }
    return res;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);

    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;

    return 0;
}