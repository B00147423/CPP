#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> medians(vector<int> values, int k) {
    int n = values.size();
    vector<int> mediansList;

    for (int i = 0; i + k <= n; i++) {
        vector<int> temp(values.begin() + i, values.begin() + i + k);
        sort(temp.begin(), temp.end());
        int median = temp[k / 2];
        mediansList.push_back(median);
    }

    int maxMed = *max_element(mediansList.begin(), mediansList.end());
    int minMed = *min_element(mediansList.begin(), mediansList.end());
    return {maxMed, minMed};
}

int main() {
    int n, k;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) cin >> values[i];
    cin >> k;

    vector<int> result = medians(values, k);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
