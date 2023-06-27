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
};



int main(){

    return 0;
}