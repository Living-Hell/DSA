#include<bits/stdc++.h>
using namespace std;

class BST{
    public:

    //A binary tree Node
    struct Node
    {
        int data;
        struct Node* left;
        struct Node* right;
        
        Node(int x){
            data = x;
            left = right = NULL;
        }
    };

    // Function to search a node in BST (using recursion)
    bool searchRec(Node* root, int x) {
        if(root==NULL) return false;
        if(root->data == x) return true;
        if(root->data>x) return searchRec(root->left,x);
        else return searchRec(root->right,x);
    }

    // Function to search a node in BST (using iteration)
    bool searchItr(Node* root, int x) {
        while(root){
            if(!root) return false;
            if(root->data == x) return true;
            else if(root->data>x) root = root->left;
            else root = root->right;
        }
        return false;
    }

    // Function to delete a node from BST
    Node* deleteNode(Node* root, int key) {
        if(!root) return NULL;

        if(key > root->data) root->right = deleteNode(root->right, key);
        else if(key < root->data) root->left =  deleteNode(root->left,key);
        else{
            if(root->left == NULL) return root->right;
            else if(root->right == NULL) return root->left;
            
            Node* temp = root->right;
            while(temp->left != NULL) temp = temp -> left;
            root->data = temp->data;
            
            root->right = deleteNode(root->right, root->data);
            
        }
        return root;
    }

    // Function to find the maximum element in the given BST.
    int findMax(Node *root){
        if(!root) return -1;
        while(root->right) root = root->right;
        return root->data;
    }

    // Function to find the minimum element in the given BST.
    int findMin(Node *root){
        if(!root) return -1;
        while(root->left) root = root->left;
        return root->data;
    }

    // To find predecessor and successor of key in BST. It sets pre and suc as predecessor and successor.
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
        if(!root) return;
        
        if(key>root->key){
            if(pre==NULL || pre->key<root->key )
                pre = root;
            findPreSuc(root->right,pre,suc,key);
        }
        else if(key<root->key){
            if(suc == NULL || suc->key>root->key)
                suc = root;
            findPreSuc(root->left,pre,suc,key);
        }
        
        else{
            if(root->left){
                pre = root->left;
                while(pre->right) pre = pre->right;
            }
            if(root->right){
                suc = root->right;
                while(suc->left) suc = suc->left;
            }
        }
    }

};

int main(){
    BST bst;

    return 0;
}