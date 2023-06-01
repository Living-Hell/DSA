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

int main(){
    return 0;
}