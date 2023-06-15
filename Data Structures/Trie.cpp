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

    //Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.
    bool searchWordBreak(string s, TrieNode* root, Trie trie){
        if(s.size()==0) return 1;
        for(int i=1; i<=s.size(); i++){
            if(trie.search(root,s.substr(0,i)) && searchWordBreak(s.substr(i),root,trie)){
                return 1;
            }
        }
        return 0;
    }
    int wordBreak(string A, vector<string> &B){
        TrieNode *root = new TrieNode();
        Trie trie;
        for(string word : B) trie.insert(root,word);
        return searchWordBreak(A,root,trie);
    }

    //Given an array of strings, return all groups of strings that are anagrams. 
    //The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        vector<string> temp = string_list;
        TrieNode *root = new TrieNode();
        Trie trie;
        map<string,vector<int>> mp;
        
        for(int i=0; i<temp.size(); i++){
            trie.insert(root,temp[i]);
            sort(temp[i].begin(), temp[i].end());
        }
        
        for(int i=0; i<string_list.size(); i++){
            mp[temp[i]].push_back(i);
        }
        
        vector<vector<string>> ans;
        for(auto i: mp){
            vector<string> t;
            for(int j=0; j<i.second.size(); j++){
                if(trie.search(root,string_list[i.second[j]]))
                    t.push_back(string_list[i.second[j]]);
            }
            ans.push_back(t);
        }
        return ans;
    }

    //Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory 
    //and a query string s. The task is to implement a search query for the phone directory. Run a search 
    //query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct
    // contacts which have the same prefix as p in lexicographical increasing order.
    void allContact(TrieNode *root, vector<string> &v, string s){
        if(root->isEndOfWord){
            v.push_back(s);
        }
        for(int i=0; i<26; i++){
            if(root->children[i] != NULL){
                s+= ('a' + i);//cout<<s<<" ";
                allContact(root->children[i],v,s);
                s.pop_back();
            }
        }
    }
    void searchContact(TrieNode *root, string s, vector<string> &v){
        int n = s.size();
        bool flag = 1;
        for(int i=0; i<n; i++){
            int ind = s[i]-'a';
            if(root->children[ind] != NULL) root = root->children[ind];
            else{
                flag = 0;
                break;
            }
        }
        if(flag){
            allContact(root,v,s);
        }
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s){
        Trie trie;
        TrieNode *root = new TrieNode();
        for(int i=0; i<n; i++) trie.insert(root,contact[i]);
        vector<vector<string>> ans;
        for(int i=1; i<=s.size(); i++){
            string word = s.substr(0,i);
            vector<string> temp;
            searchContact(root,word,temp);
            if(temp.empty()) ans.push_back({"0"});
            else{ 
                sort(temp.begin(),temp.end());
                ans.push_back(temp);
                
            }
        }
        return ans;
    }

    //Given a binary matrix your task is to find all unique rows of the given matrix in the order of their appearance in the matrix. 
    struct rowNode{
        int data;
        rowNode *child[2];
        bool isEnd;
        rowNode(int val){
            data = val;
            child[0] = child[1] = NULL;
            isEnd = false;
        }
    };
    void insertRow(rowNode *root, int *arr, int col){
        for(int i=0; i<col; i++){
            int ind = arr[i];
            if(root->child[ind] == NULL){
                root->child[ind] = new rowNode(ind);
            }
            root = root->child[ind];
        }
        root->isEnd = true;
    }
    bool rowPresent(rowNode *root, int *arr, int col){
        for(int i=0; i<col; i++){
            int ind = arr[i];
            if(root->child[ind] == NULL){
                return false;
            }
            root = root->child[ind];
        }
        return root->isEnd;
    }
    vector<vector<int>> uniqueRow(int M[1000][1000],int row,int col){
        rowNode *root = new rowNode('\0');
        vector<vector<int>> ans;
        for(int i=0; i<row; i++){
            if(!rowPresent(root,M[i],col)){
                insertRow(root,M[i],col);
                vector<int> temp(M[i], M[i]+col);
                ans.push_back(temp);
            }
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