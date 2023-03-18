#include<bits/stdc++.h>
using namespace std;

class BinaryTree{
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

    //Function to return the level order traversal of a tree.
    vector<int> levelOrderTraversal(Node* node)
    {
      vector<int> ans;
      if(!node) return ans;
      queue<Node*> q;
      q.push(node);
      while(!q.empty()){
          Node* top = q.front();
          q.pop();
          ans.push_back(top->data);
          if(top->left) q.push(top->left);
          if(top->right)q.push(top->right);
      }
      return ans;
    }

    //Function to find its reverse level order traversal. ie- the traversal must begin from the last level. 
    vector<int> reverseLevelOrder(Node *root)
    {
        vector<int> ans;
        if(!root) return ans;
        queue<Node*> q;
        stack<int> st;
        q.push(root);
        while(!q.empty()){
            Node* top = q.front();
            q.pop();
            st.push(top->data);
            if(top->right) q.push(top->right);
            if(top->left)q.push(top->left);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    //Function to find the height of a binary tree (using iteration)
    int heightOfBT(struct Node* node){
        queue<pair<Node*,int>> q;
        int ans=0;
        if(!node) return ans;
        q.push({node,1});
        while(!q.empty()){
            auto top = q.front(); q.pop();
            int lvl = top.second;
            Node* root = top.first;
            ans = max(ans,lvl);
            if(root->left) q.push({root->left,lvl+1});
            if(root->right) q.push({root->right,lvl+1});
        }
        return ans;
    }
    //Function to find the height of a binary tree (using recursion)
    int heightofBT(struct Node* node){
        if(!node) return 0;
        return max(heightofBT(node->left),heightofBT(node->right))+1;
    }

    // Function to return the diameter of a Binary Tree.
    int findDia(Node* root, int &ans){
        if(!root) return 0;
        int lh = findDia(root->left,ans);
        int rh = findDia(root->right,ans);
        ans = max(ans,lh+rh+1);
        return 1+max(lh,rh);
    }
    int diameterofBT(Node* root) {
        if(!root) return 0;
        int ans=0;
        findDia(root,ans);
        return ans;
    }

    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(!node)return;
        swap(node->left,node->right);
        mirror(node->left);
        mirror(node->right);
    }

    // Function to return a list containing the inorder traversal of the tree using Recursion.
    void IO(Node* root, vector<int> &ans){
        if(!root) return;
        IO(root->left,ans);
        ans.push_back(root->data);
        IO(root->right,ans);
    }
    vector<int> inOrderRec(Node* root) {
        vector<int> ans;
        IO(root,ans);
        return ans;
    }

    // Function to return a list containing the inorder traversal of the tree using Iteration.
    vector<int> inOrderItr(Node* root){
        vector<int> ans;
        stack<Node*> st;
        while(1){
            if(root != NULL){
                st.push(root);
                root = root->left;
            }
            else{
                if(st.empty()) return ans;
                root = st.top();
                st.pop();
                ans.push_back(root->data);
                root=root->right;
            }
        }
        return ans;
    }

    //Function to return a list containing the preorder traversal of the tree using Recusrion.
    void Preorder(Node* root, vector<int> &ans){
        if(!root) return;
        ans.push_back(root->data);
        Preorder(root->left,ans);
        Preorder(root->right,ans);
    }
    vector <int> preorder(Node* root)
    {
        vector<int> ans;
        Preorder(root,ans);
        return ans;
    }

    //Function to return a list containing the preorder traversal of the tree using Iteration.
    vector<int> preOrder(Node* root){
        vector<int> ans;
        stack<Node*> st;
        while(1){
            if(root != NULL){
                ans.push_back(root->data);
                st.push(root);
                root = root->left;
            }
            else{
                if(st.empty()) return ans;
                root = st.top();
                st.pop();
                root = root->right;
            }
        }
        return ans;
    }

};

int main(){
    BinaryTree bt;

    return 0;
}