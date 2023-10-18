#include<bits/stdc++.h>
using namespace std;
// define node for Trie Tree
class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord;
        TrieNode(){
            isEndOfWord = false;
        };
};
class Trie {
    private:
        TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        };
        // funtion insert a word to Trie Tree
        void insert(const string& word){
            TrieNode* current = root;
            for(char ch: word){
                // if current node has not child ch, create new node
                if(!current -> children[ch]){
                    current -> children[ch] = new TrieNode();
                };
                current = current -> children[ch];
            };
            // mark current node as end of word
            current -> isEndOfWord = true;
        };
        // funtion find all words in Trie Tree
        bool search(const string& word){
            TrieNode* current = root;
            for(char ch: word){
                if(!current -> children[ch]){
                    // if current node has not child ch, return false
                    return false;
                };
                current = current -> children[ch];
            };
            // if current node is end of word, return true
            return current -> isEndOfWord;
        };
};