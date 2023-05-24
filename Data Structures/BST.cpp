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

    //Function to Construct Binary Search Tree from Preorder Traversal
    int ind = 0; 
    Node* solve(vector<int>& pre, int bound) {
        if(ind>=pre.size() or pre[ind] > bound) return NULL;
        Node* root = new Node(pre[ind++]);
        root->left = solve(pre,root->data);
        root->right = solve(pre,bound);
        return root; 
    }
    Node* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,INT_MAX);
    }

    // The given root is the root of the Binary Tree. Return the root of the generated BST
    void inorder(Node *root, vector<int> &v){
        if(!root) return;
        
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    Node *VtoBST(Node* root, vector<int> v, int i){
        if(i>= v.size()) return root;
        Node *temp = new Node(v[i]);
        if(root->data > v[i]){
            root->left = temp;
            VtoBST(root->left, v, i+1);
        }
        else{
            root->right = temp;
            VtoBST(root->right, v, i+1);
        }
        return root;
    }
    // void VtoBST(Node* root, vector<int> v, int &i){
    //     if(!root) return;
    //     VtoBST(root->left,v,i);
    //     root->data = v[i++];
    //     VtoBST(root->right,v,i);
    // }
    Node *binaryTreeToBST (Node *root){
        vector<int> v;
        inorder(root,v);
        sort(v.begin(),v.end());
        Node *ans = new Node(v[0]);
        return VtoBST(ans,v,1);
    }

    //Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height.
    void inorder(Node* root, vector<int> &v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    Node* BBST(vector<int> io, int st, int end){
        if(st > end) return NULL;
        int mid = (st+end)/2; 
        Node* ans = new Node(io[mid]);
        ans->left = BBST(io, st, mid-1);
        ans->right = BBST(io, mid+1, end);
        return ans;
    }
    Node* buildBalancedTree(Node* root){
        vector<int> v;
        inorder(root,v);
        return BBST(v, 0, v.size()-1);
    }

    //Given two BSTs, return elements of both BSTs in sorted form.
    vector<int> merge2BST(Node *root1, Node *root2){
       vector<int> io1, io2;
       inorder(root1,io1);
       inorder(root2,io2);
       int i1=0, i2=0;
       vector<int> ans;
       while(i1 < io1.size() and i2 < io2.size()){
           if(io1[i1] <= io2[i2]){
               ans.push_back(io1[i1]);
               i1++;
           }
           else{
               ans.push_back(io2[i2]);
               i2++;
           }
       }
       if(i2>=io2.size()){
           for(int i=i1; i<io1.size(); i++) ans.push_back(io1[i]);
       }
       else{
           for(int i=i2; i<io2.size(); i++) ans.push_back(io2[i]);
       }
       return ans;
    }

};

int main(){
    BST bst;

    return 0;
}