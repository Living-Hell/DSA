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
    int child_count=0;
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
        root->child_count++;
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

    //Given an array of words, find all shortest unique prefixes to represent each word in the given array.
    void shortestPrefixes(TrieNode* root, string word, vector<string> &ans){
        string temp = word.substr(0,1);
        for(int i=0; i<word.size(); i++){
            int ind = word[i] - 'a';
            int count = root->children[ind]->child_count;
            if(count>1)
                temp = word.substr(0,i+2);
            root = root->children[ind];
        }
        ans.push_back(temp);
    }
    vector<string> findPrefixes(string arr[], int n){
        TrieNode* root = new TrieNode();
        Trie trie;
        for(int i=0; i<n; i++) 
            trie.insert(root,arr[i]);
        vector<string> ans;
        for(int i=0; i<n; i++){
            shortestPrefixes(root,arr[i],ans);
        }
        return ans;
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