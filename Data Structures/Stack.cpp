#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Stack{
    public:
    //Function to print the linked list
    void printList(Node *node){
        while(node){
            cout<<node->data<<" ";
            node = node->next;
        }
        cout<<endl;
    }

    //Function to reverse a given linked list of n nodes
    //Iterative - Using stack
    Node* reverseListItr(Node *node){
        Node *rev; Node *temp;
        rev = temp;
        stack<int> st;
        while(node){
            st.push(node->data);
            node = node->next;
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();
            temp->next = new Node(top);
            temp = temp->next;
        }
        return rev->next;        
    }
    //Iterative2 - Using 3 pointers
    Node* reverseListItr2(Node *head){
        Node* prev = NULL; Node* curr = head; Node* next = head->next;
        while(next){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
    }
    //Recursive solution
    Node* reverseListRec(Node *head){
        if(head == NULL || head->next == NULL) return head;
        Node* newHead = reverseListRec(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }

    //Given a linked list of size N. The task is to reverse every k nodes in the linked list.
    Node *reverse(Node *head, int k){ 
        stack<int> st;
        Node* temp = new Node(0); Node* ans = temp;
        while(head!= NULL){
            for(int i=0; i<k and head!= NULL; i++){
                st.push(head->data);
                head = head->next;
            }
            while(!st.empty()){
                int top = st.top(); st.pop(); 
                Node* t = new Node(top); 
                temp->next = t;
                temp = temp->next;
            }
        }
        return ans->next;
    }

};

int main(){
    Stack st;
    Node *head = NULL;
    Node *temp = NULL;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int data;
        cin>>data;
        if(i==0){
            head = new Node(data);
            temp = head;
        }
        else{
            temp->next = new Node(data);
            temp = temp->next;
        }
    }

    st.printList(head);
    Node *rev = st.reverseListItr(head);
    st.printList(rev);
    return 0;
}