#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode *children[26];
    bool isEndOfWord; 

    TrieNode(){
        isEndOfWord = false;
        for(int i=0; i<26; i++) children[i] = NULL;
    }
};

class Trie{
    public:

    //Function to insert string into TRIE.
    void insert(TrieNode *root, string key){
        if(key.size() == 0){ 
            root->isEndOfWord = true;
            return;
        }
        int ind = key[0] - 'a';
        TrieNode* child;
        if(root->children[ind] == NULL){
            child = new TrieNode();
            root->children[ind] = child;
        }
        else{
            child = root->children[ind];
        }
        insert(child,key.substr(1));
    }

    //Function to use TRIE data structure and search the given string.
    bool search(TrieNode *root, string key) {
        if(key.size() == 0) return root->isEndOfWord;
        int ind = key[0] - 'a';
        TrieNode* child;
        if(root->children[ind] == NULL){
            child = new TrieNode();
            return false;
        }
        child = root->children[ind];
        return search(child,key.substr(1));
    }

};

int main(){
    Trie trie;
    TrieNode* root = new TrieNode;
    // trie.insert(root,"asdds");
    // trie.insert(root,"abcd");
    // trie.insert(root,"asd");
    // cout<<trie.search(root,"abcd");
    // cout<<trie.search(root,"abd");

    return 0;
}