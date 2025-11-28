#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'crosswordPuzzle' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY crossword
 *  2. STRING words
 */
bool backtrack(vector<string>& crossword, vector<string>& wordList, int wordIndex) {
    if(wordIndex == wordList.size()){
        return true;
    }

    string word = wordList[wordIndex];
    std::cout << "word:  " << word << endl;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            // Horizontal
            if(j + word.size() <= 10){
                bool valid = true;
                for(int k = 0; k < word.size(); k++){
                    if(crossword[i][j+k] != '-' && crossword[i][j+k] != word[k]){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    vector<string> temp = crossword;
                    for(int k = 0; k < word.size(); k++){
                        crossword[i][j+k] = word[k];
                    }
                    if(backtrack(crossword, wordList, wordIndex+1)) return true;
                    crossword = temp;
                }
            }
            
            // Vertical
            if(i + word.size() <= 10){
                bool valid = true;
                for(int k = 0; k < word.size(); k++){
                    if(crossword[i+k][j] != '-' && crossword[i+k][j] != word[k]){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    vector<string> temp = crossword;
                    for(int k = 0; k < word.size(); k++){
                        crossword[i+k][j] = word[k];
                    }
                    if(backtrack(crossword, wordList, wordIndex+1)) return true;
                    crossword = temp;
                }
            }
        }
    }
    return false;
}

vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector<string> wordList;
    string current = "";
    for(char c : words) {
        if(c == ';') {
            wordList.push_back(current);
            current = "";
        } else {
            current += c;
        }
    }
    wordList.push_back(current);
    
    backtrack(crossword, wordList, 0);
    return crossword;
}
