#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>


/*
 * Complete the 'countResponseTimeRegressions' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY responseTimes as parameter.
 */

int countResponseTimeRegressions(std::vector<int> responseTimes) {
    int n = responseTimes.size();
    int count = 0;
    
    if(n <= 1)return 0;

    double sum = responseTimes[0];
    for(int i = 1; i < n; i++){
        double avarage = sum / i;
        if(responseTimes[i] > avarage) count++;
    
        sum+= responseTimes[i];
    }
    return count;
}

int main() {
    std::vector<int> responseTimes = {100, 200, 150, 300, 250};
    int result = countResponseTimeRegressions(responseTimes);
    std::cout << "Number of response time regressions: " << result << std::endl;
    return 0;
}
