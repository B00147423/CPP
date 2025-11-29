#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;


string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */
 
int backtrack(int num){
    //BASE CASE single digit already
    if(num < 10) {
        return num;
    }
    
    int sum = 0;
    
    while(num > 0){
        sum += num % 10;  // Get last digit of num
        num /= 10; 
    }
    return backtrack(sum);
}

int superDigit(string n, int k) {
    long long sum = 0;
    for(char c : n) {
        sum += (c - '0');
    }
    
    //find super digit recursively
    // to avoid any potential overflow issues
    int firstSuper = backtrack(sum);
    
    //multiply by k and find super digit again
    long long total = (long long)firstSuper * k;
    return backtrack(total);
}
