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

};

int main(){
    BST bst;

    return 0;
}