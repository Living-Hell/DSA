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
        struct Node* next;
        
        Node(int x){
            data = x;
            left = right = next = NULL;
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
        
        if(key>root->data){
            if(pre==NULL || pre->data<root->data )
                pre = root;
            findPreSuc(root->right,pre,suc,key);
        }
        else if(key<root->data){
            if(suc == NULL || suc->data>root->data)
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

    //Function to check whether a Binary Tree is BST or not.
    bool IsBST(Node* root, int curr_min, int curr_max){
        if(!root) return true;
        return root->data > curr_min and root->data < curr_max
        and IsBST(root->left,curr_min, root->data)
        and IsBST(root->right, root->data, curr_max);
        
    }
    bool isBST(Node* root) {
        return IsBST(root,INT_MIN,INT_MAX);
    }

    //Function to populate next pointer for all nodes. 
    //The next pointer for every node should be set to point to inorder successor.
    Node* prev=NULL;
    void populateNext(Node *root){
        if(!root) return;
        populateNext(root->left);
        if(prev)
            prev->next = root;
        prev = root;
        populateNext(root->right);
    }

    //Function to find the lowest common ancestor in a BST. 
    Node* lca2Nodes(Node* root, int n1, int n2){
        if(!root) return NULL;
        if(root->data >= n1 and root->data <= n2) return root;
        else if(root->data < n1) return lca2Nodes(root->right,n1,n2);
        else return lca2Nodes(root->left,n1,n2);
    }
    Node* LCA(Node *root, int n1, int n2){
    return lca2Nodes(root,min(n1,n2),max(n1,n2));
    }

};

int main(){
    BST bst;

    return 0;
}