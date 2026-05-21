// 211. Design Add and Search Words Data Structure
//Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
#include <unordered_map>
#include <string>
using namespace std;

class WordDictionary {
        struct TrieNode{
            unordered_map<char, TrieNode*> children;
            bool endWord = false;
        };
        TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
    
        for(char c: word){
            if(curr->children.find(c) == curr->children.end()){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endWord = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int i, TrieNode* curr) {

        if(i == word.size()){
            return curr->endWord;
        }
        char c = word[i];
        if (c != '.') {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            return dfs(word, i + 1, curr->children[c]);
        }

        // c == "."
        for(auto& child : curr->children){
            if(dfs(word, i+1, child.second)){
                return true;
            }
        }
        return false;
    }
};
/*
we need a way tio track previous added word

use a map? 


*/
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */