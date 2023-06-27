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

//Queue Implementation using array
class ArrQueue{
private:
    int front, rear;
    int arr[100005];
public:   
    ArrQueue(){
        front=0;
        rear=0;
    }
    //Function to push an element x in a queue.
    void push(int x){
            arr[front++] = x;
    }
    //Function to pop an element from queue and return that element.
    int pop(){
            return (front == rear) ? -1 : arr[rear++];      
    }
};

class StackQueue{
private:   
    stack<int> s1;
    stack<int> s2;
public:
    //Function to push an element in queue by using 2 stacks.
    void  push(int x){
        s1.push(x);
    }
    //Function to pop an element from queue by using 2 stacks.
    int pop(){
        while(!s1.empty()){
            int top = s1.top();
            s1.pop();
            s2.push(top);
        } 
        if(s2.empty()) 
            return -1;
        int data = s2.top();
        s2.pop();
        while(!s2.empty()){
            int top = s2.top(); s2.pop();
            s1.push(top);
        }
        return data;            
    }
};

//Implementation of 2 stacks using 1 array
class twoStacks{
    int *arr;
    int size;
    int top1, top2;
    public:    
    twoStacks(int n=100){
        size = n; 
        arr = new int[n]; 
        top1 = -1; 
        top2 = size;
    } 
    //Function to push an integer into the stack1.
    void push1(int x){
        arr[++top1] = x;
    }    
    //Function to push an integer into the stack2.
    void push2(int x){
       arr[--top2] = x;
    }    
    //Function to remove an element from top of the stack1.
    int pop1(){
        return top1 == -1 ? -1 : arr[top1--];
    }    
    //Function to remove an element from top of the stack2.
    int pop2(){
       return top2 == size ? -1 : arr[top2++];
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

    //

};

struct QueueNode{
    int data;
    QueueNode *next;
    QueueNode(int a){
        data = a;
        next = NULL;
    }
};
class Queue{
private:
    QueueNode *front;
    QueueNode *rear;
public:
    Queue(){
        front = rear = NULL;
    }
    //Function to push an element into the queue.
    void push(int x){
            QueueNode* node = new QueueNode(x);
            if(!front) front = rear = node;
            else{
                rear->next = node;
                rear = node;
            }
    }
    //Function to pop front element from the queue.
    int pop(){
            if(!front) return -1;
            int data = front->data;
            front = front->next;
            return data;
    }

    //

};


int main(){

    return 0;
}