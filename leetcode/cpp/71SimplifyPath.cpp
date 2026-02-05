// 71. Simplify Path
// https://leetcode.com/problems/simplify-path/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {

    /*
    
    Input: path = "/home/user/Documents/../Pictures"

Output: "/home/user/Pictures"

Explanation:

A double period ".." refers to the directory up a level (the parent directory).
    */
public:
    string simplifyPath(string path) {
        vector<string> stack;

        stringstream ss(path);
        string temp;

        while (getline(ss, temp, '/')) { // []
            if (temp == "..") {
                if(!stack.empty()) stack.pop_back();
            }else if (temp != "." && !temp.empty()) {
                stack.push_back(temp); //stack = [home, user, pictures]
            }
        }


        //stack =[home, user, pictures]
        string res = ""; 
        
        for (auto str : stack) res += "/" + str;
        if(res.empty()) 
            return "/";
        else
            return res; //"home/user/pictures"

    }
};