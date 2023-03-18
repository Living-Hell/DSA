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
    
};

int main(){
    BinaryTree bt;

    return 0;
}