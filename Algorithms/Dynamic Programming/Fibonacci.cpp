#include <iostream>
#include <vector>
using namespace std;


vector<int> memo(100, -1);
static int counter = 0;

int fib(int n){
    counter++;
    if(memo[n] != -1){
        return memo[n];
    }

    if(n == 0 || n == 1){
        return n;
    }

    memo[n]=fib(n - 1) + fib(n - 2);

    return memo[n];

}

int main(){
    
    int n = 7;
    cout << "\nfib of " << n << " = " << fib(n);
    cout << "\n\nCounter:" << counter << endl;
}