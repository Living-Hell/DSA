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

    //Merging two BSTs using stack 
    void mergeUtil(Node *root, stack<Node*> &st){
        if(!root) return;
        st.push(root);
        mergeUtil(root->left,st);
    }
    vector<int> mergeBST(Node *root1, Node *root2){
        stack<Node*> st1, st2;
        mergeUtil(root1,st1);
        mergeUtil(root2,st2);
        vector<int> ans;
       
        while(!st1.empty() and !st2.empty()){
            Node* top1 = st1.top(); Node* top2 = st2.top();
            if(top1->data > top2->data){
                ans.push_back(top2->data);
                st2.pop();
                mergeUtil(top2->right,st2);
            }
            else{
                ans.push_back(top1->data);
                st1.pop();
                mergeUtil(top1->right,st1);
            }
        }       
        if(st1.empty()){
            while(!st2.empty()){
                Node* top = st2.top();
                ans.push_back(top->data);
                st2.pop();
                mergeUtil(top->right,st2);
            }
        }
        else{
            while(!st1.empty()){
                Node* top = st1.top();
                ans.push_back(top->data);
                st1.pop();
                mergeUtil(top->right,st1);
            }
        }
        return ans;
    }

    // return the Kth largest element in the given BST rooted at 'root'
    int kthLargest(Node *root, int k){
        if(!root) return -1;
        stack<Node*> st;
        while(root){
            st.push(root);
            root = root->right;
        }
        
        while(!st.empty()){
            Node* top = st.top();
            st.pop();
            k--;
            if(k==0) return top->data;
            top = top->left;
            if(top){
                while(top){
                    st.push(top);
                    top = top->right;
                }
            }
        }
        return -1;
    }

    // Return the Kth smallest element in the given BST
    void kthsmallest(Node* root, int k, int &cnt, int &ans){
        if(!root) return;
        kthsmallest(root->left,k,cnt,ans);
        cnt++;
        if(k == cnt) ans = root->data;
        kthsmallest(root->right,k,cnt,ans);
    }
    int KthSmallestElement(Node *root, int k) {
        int cnt=0, ans=-1;
        kthsmallest(root,k,cnt,ans);
        return ans;
    }

    //Function to return the count of all pairs from both the BSTs whose sum is equal to x.
    int pairs=0;
    void countInorder(Node* root, Node* root2, int x){
        if(!root) return;
        countInorder(root->left, root2, x);
        searchPairs(root2,x,x-root->data);
        countInorder(root->right, root2, x);
    }
    void searchPairs(Node* root, int x, int val){
        if(!root) return;
        if(root->data == val) pairs++;
        else if(root->data > val){
            searchPairs(root->left, x, val);
        }
        else if(root->data < val){
            searchPairs(root->right,x,val);
        }
    }
    int countPairs(Node* root1, Node* root2, int x){
        countInorder(root1,root2,x);
        return pairs;
    }

    //Given a Binary Search Tree of size N, find the Median of its Node values.
    int nodeCount=0, currCount=0; float median=0;
    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        nodeCount++;
        inorder(root->right);
    }
    void searchNth(Node* root, int n){
        if(!root) return;
        searchNth(root->left, n);
        currCount++;
        if(currCount == n){
            if(median == 0) median = root->data;
            else median = (median + root->data)/2;
        }
        searchNth(root->right,n);
    }
    float findMedian(Node *root){
        inorder(root);
        if(nodeCount%2==1) searchNth(root,nodeCount/2 +1);
        else{
            searchNth(root,nodeCount/2);
            currCount=0;
            searchNth(root,nodeCount/2+1);
        }
        return median;
    }

    //Function to count number of nodes in BST that lie in the given range.
    void getcount(Node *root, int l, int h, int &ans){
        if(!root) return;
        getcount(root->left,l,h,ans);
        if(root->data >= l and root->data <= h) ans++;
        getcount(root->right,l,h,ans);
    }
    int getCount(Node *root, int l, int h){
      int ans = 0;
      getcount(root,l,h,ans);
      return ans;
    }

};

int main(){
    BST bst;

    return 0;
}