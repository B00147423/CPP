
// 316. Remove Duplicate Letters
// https://leetcode.com/problems/remove-duplicate-letters/
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {

    vector<int> lastOccurance(26);

    for (int i = 0; i < s.size(); i++) {
        lastOccurance[s[i] - 'a'] = i;
    }

    vector<bool> seenCharacter(26, false);
    string chararacterStack;


    for(int i = 0; i < s.size(); i++){
        char currentChar = s[i];
        int charIndex = currentChar - 'a';

        if(seenCharacter[charIndex]) continue;

        while (!chararacterStack.empty() && 
                currentChar < chararacterStack.back() && 
                lastOccurance[chararacterStack.back() - 'a'] > i) 
        {
            seenCharacter[chararacterStack.back() - 'a'] = false;
            chararacterStack.pop_back();
        }
        chararacterStack.push_back(currentChar);
        seenCharacter[currentChar - 'a'] = true;
    }
        return chararacterStack;
    }
};

/*
Example 1:
Input: s = "bcabc"
Output: "abc"

 = "bcabc"
last[a]=2 last[b]=3 last[c]=4
stack=""
seen[a]=false seen[b]=false seen[c]=false
dry run: 

i=0 currentChar='b'
seen[b]=false
stack empty
push 'b'
stack="b"
seen[b]=true

i=1 currentChar='c'
seen[c]=false
'c'<'b' false
push 'c'
stack="bc"
seen[c]=true

i=2 currentChar='a'
seen[a]=false
'a'<'c' true AND last['c']=4>2 true -> pop 'c'
seen[c]=false
stack="b"
'a'<'b' true AND last['b']=3>2 true -> pop 'b'
seen[b]=false
stack=""
push 'a'
stack="a"
seen[a]=true

i=3 currentChar='b'
seen[b]=false
'b'<'a' false
push 'b'
stack="ab"
seen[b]=true

i=4 currentChar='c'
seen[c]=false
'c'<'b' false
push 'c'
stack="abc"
seen[c]=true


*/