#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>

/*
 * Complete the 'generateAngleBracketSequences' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts INTEGER n as parameter.
 */
void backtrack(std::vector<std::string>& result, std::string current, int open, int close, int n){
    // If the current string has 2*n characters, it's complete
   if(current.length() == 2 * n){
        result.push_back(current);
        return;
   } 
   
   // Add '<' if we haven't used all open brackets yet
   if (open < n) {
        backtrack(result, current + "<", open+1, close, n);
   }
    // Add '>' if there are unmatched '<' brackets
    if(close < open){
        backtrack(result, current + ">", open, close+1, n);
    }
}
std::vector<std::string> generateAngleBracketSequences(int n) {
    std::vector<std::string> result;
    backtrack(result, "", 0, 0, n);
    return result;
}
