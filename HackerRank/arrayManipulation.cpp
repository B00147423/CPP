#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

long arrayManipulation(int n, vector<vector<int>> queries) {
        vector<long> diff(n+2, 0);
        
        for(const auto& q : queries){
            int a = q[0];
            int b = q[1];
            int k = q[2]; 
            diff[a] +=k;
            diff[b+1] -=k;
        }
        // build prefix sum and track maximum
        long maxVal = 0;
        long current = 0;
        
        for(int i = 1; i <= n; i++){
            current += diff[i];
            maxVal = max(maxVal, current);
        }
        return maxVal;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}
