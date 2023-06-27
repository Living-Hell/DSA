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

int main(){

    return 0;
}