#include<bits/stdc++.h>
using namespace std;

//Stack Implementation using array
class ArrStack{
private:
    int top;
	int arr[1000];
public:
    ArrStack(){
		top = -1;
	}	
	//Function to push an integer into the stack.
    void push(int a){
	    arr[++top] = a;
	} 	
    //Function to remove an item from top of the stack.
	int pop(){
        return top >= 0 ? arr[top--] : -1;
	}
};

struct StackNode{
    int data;
    StackNode *next;
    StackNode(int x){
        data = x;
        next = NULL;
    }
};

//Implementation of Stack using Linked list
class Stack{
    private:
        StackNode *top;
    public:
    Stack(){
        top = NULL;
    }
    //Function to push an integer into the stack.
    void push(int x) {
        StackNode *node = new StackNode(x);
        if(!top) top = node;
        else{
            node->next = top;
            top = node;
        }
    }
    //Function to remove an item from top of the stack.
    int pop(){
        if(top == NULL) return -1;
        else{
            int ret = top->data;
            top = top->next;
            return ret;
        }
    }
};

int main(){

    return 0;
}