#include <bits/stdc++.h>
using namespace std;

// Stack Implementation using array
class ArrStack
{
private:
    int top;
    int arr[1000];

public:
    ArrStack()
    {
        top = -1;
    }
    // Function to push an integer into the stack.
    void push(int a)
    {
        arr[++top] = a;
    }
    // Function to remove an item from top of the stack.
    int pop()
    {
        return top >= 0 ? arr[top--] : -1;
    }
};

// Queue Implementation using array
class ArrQueue
{
private:
    int front, rear;
    int arr[100005];

public:
    ArrQueue()
    {
        front = 0;
        rear = 0;
    }
    // Function to push an element x in a queue.
    void push(int x)
    {
        arr[front++] = x;
    }
    // Function to pop an element from queue and return that element.
    int pop()
    {
        return (front == rear) ? -1 : arr[rear++];
    }
};

class StackQueue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    // Function to push an element in queue by using 2 stacks.
    void push(int x)
    {
        s1.push(x);
    }
    // Function to pop an element from queue by using 2 stacks.
    int pop()
    {
        while (!s1.empty())
        {
            int top = s1.top();
            s1.pop();
            s2.push(top);
        }
        if (s2.empty())
            return -1;
        int data = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            int top = s2.top();
            s2.pop();
            s1.push(top);
        }
        return data;
    }
};

// Implementation of 2 stacks using 1 array
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    // Function to push an integer into the stack1.
    void push1(int x)
    {
        arr[++top1] = x;
    }
    // Function to push an integer into the stack2.
    void push2(int x)
    {
        arr[--top2] = x;
    }
    // Function to remove an element from top of the stack1.
    int pop1()
    {
        return top1 == -1 ? -1 : arr[top1--];
    }
    // Function to remove an element from top of the stack2.
    int pop2()
    {
        return top2 == size ? -1 : arr[top2++];
    }
};

struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int x)
    {
        data = x;
        next = NULL;
    }
};
// Implementation of Stack using Linked list
class Stack
{
private:
    StackNode *top;

public:
    Stack()
    {
        top = NULL;
    }
    // Function to push an integer into the stack.
    void push(int x)
    {
        StackNode *node = new StackNode(x);
        if (!top)
            top = node;
        else
        {
            node->next = top;
            top = node;
        }
    }
    // Function to remove an item from top of the stack.
    int pop()
    {
        if (top == NULL)
            return -1;
        else
        {
            int ret = top->data;
            top = top->next;
            return ret;
        }
    }

    //
};

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};
class Queue
{
private:
    QueueNode *front;
    QueueNode *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }
    // Function to push an element into the queue.
    void push(int x)
    {
        QueueNode *node = new QueueNode(x);
        if (!front)
            front = rear = node;
        else
        {
            rear->next = node;
            rear = node;
        }
    }
    // Function to pop front element from the queue.
    int pop()
    {
        if (!front)
            return -1;
        int data = front->data;
        front = front->next;
        return data;
    }
};

class StackQueue
{
public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        stack<int> st;
        int mid = sizeOfStack / 2;
        while (mid--)
        {
            int top = s.top();
            s.pop();
            st.push(top);
        }
        s.pop();
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            s.push(top);
        }
    }

    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] == '[' or x[i] == '(' or x[i] == '{')
            {
                st.push(x[i]);
            }
            else
            {
                if (st.empty())
                    return 0;
                else if (x[i] == ']')
                {
                    if (st.top() == '[')
                        st.pop();
                    else
                        return 0;
                }
                else if (x[i] == ')')
                {
                    if (st.top() == '(')
                        st.pop();
                    else
                        return 0;
                }
                else if (x[i] == '}')
                {
                    if (st.top() == '{')
                        st.pop();
                    else
                        return 0;
                }
            }
        }
        return st.empty();
    }

    // Function to reverse the string using stack.
    char *reverse(char *S, int len)
    {
        stack<char> st;
        for (int i = 0; i < len; i++)
            st.push(S[i]);
        for (int i = 0; i < len; i++)
        {
            S[i] = st.top();
            st.pop();
        }
        return S;
    }

    // Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull()
    // and an additional operation getMin() which should return minimum element from the SpecialStack.
    void push(stack<int> &s, int a)
    {
        s.push(a);
    }
    bool isFull(stack<int> &s, int n)
    {
        return s.size() == n;
    }
    bool isEmpty(stack<int> &s)
    {
        return s.empty();
    }
    int pop(stack<int> &s)
    {
        if (s.empty())
            return -1;
        int top = s.top();
        s.pop();
        return top;
    }
    int helper(stack<int> s)
    {
        int mn = INT_MAX;
        while (!s.empty())
        {
            mn = min(s.top(), mn);
            s.pop();
        }
        return mn;
    }
    int getMin(stack<int> &s)
    {
        return helper(s);
    }

    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long> st;
        st.push(arr[n - 1]);
        arr[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() and st.top() <= arr[i])
                st.pop();
            long long top = arr[i];
            if (st.empty())
                arr[i] = -1;
            else
                arr[i] = st.top();
            st.push(top);
        }
        return arr;
    }

    // Function to find if there is a celebrity in the party or not. ToC=O(N2) SC=O(1)
    int celebrity(vector<vector<int>> &M, int n)
    {
        int ans = -1;
        for (int j = 0; j < n; j++)
        {
            bool knows = 1;
            for (int i = 0; i < n; i++)
                if (i != j and M[i][j] == 0)
                    knows = 0;
            if (knows)
            {
                ans = j;
                break;
            }
        }
        if (ans == -1)
            return ans;
        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 1)
            {
                ans = -1;
                break;
            }
        }
        return ans;
    }
    // Function to find if there is a celebrity in the party or not.ToC=O(N) SC=O(N)
    int fasterCelebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;
        for (int i = 0; i < n; i++)
            st.push(i);
        while (st.size() > 1)
        {
            int t1 = st.top();
            st.pop();
            int t2 = st.top();
            st.pop();
            if (M[t1][t2] == 0 and M[t2][t1] == 1)
                st.push(t1);
            if (M[t2][t1] == 0 and M[t1][t2] == 1)
                st.push(t2);
        }
        if (!st.empty())
        {
            int top = st.top();
            for (int i = 0; i < n; i++)
            {
                if (i != top and (M[i][top] == 0 or M[top][i] == 1))
                {
                    st.pop();
                    break;
                }
            }
        }
        return st.empty() ? -1 : st.top();
    }

    // Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        stack<int> st;
        for (auto i : s)
        {
            if (isdigit(i))
                st.push(i - '0');
            else
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if (i == '+')
                    st.push(num1 + num2);
                else if (i == '-')
                    st.push(num1 - num2);
                else if (i == '*')
                    st.push(num1 * num2);
                else
                    st.push(num1 / num2);
            }
        }
        return st.top();
    }
};

int main()
{

    return 0;
}