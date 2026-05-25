//Leetcode 208. Implement Trie (Prefix Tree)
// Link: https://leetcode.com/problems/implement-trie-prefix-tree/

#include <unordered_map>
using namespace std;
#include <string>



class Trie {
private:
    struct TrieNode{
        unordered_map<char, TrieNode*> children;
        bool endWord = false;
    };

    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    
    
    void insert(string word) {
        
        TrieNode* curr = root;
        for(char c : word)
        {
            if(curr->children.find(c) == curr->children.end())
            {
                curr->children[c] = new TrieNode();
                
            }
            curr = curr->children[c];
        }

        curr->endWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char w : word) {
            if (curr->children.find(w) == curr->children.end()) {
                return false;
            }

            curr = curr->children[w];
        }
        return curr->endWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char p : prefix) {
            if (curr->children.find(p) == curr->children.end()) {
                return false;
            }
            curr = curr->children[p];

        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */