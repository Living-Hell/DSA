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

    return 0;
}