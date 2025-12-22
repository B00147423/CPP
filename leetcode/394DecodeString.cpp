#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        vector<string> stringStack;
        vector<int> countStack;
        string current = "";
        int k = 0;

        for(char c : s){
            if(isdigit(c)){
                k = k * 10 + (c - '0');
            }else if(c == '['){
                stringStack.push_back(current);
                countStack.push_back(k);
                current = "";
                k = 0;
            }else if( c == ']'){
                string temp = current;
                cout << "\ntemp =" << temp << endl;
                current = stringStack.back();
                stringStack.pop_back();
                int count = countStack.back();
                countStack.pop_back();
                for (int i = 0; i < count; i++) {
                    current += temp;
                }
            }else {
                current += c;
            }
        }
        return current;
    }
};