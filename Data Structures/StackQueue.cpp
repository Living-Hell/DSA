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

// Implementation of stack using 2 queue
class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    // Function to push an element into stack using two queues.
    void push(int x)
    {
        q1.push(x);
    }

    // Function to pop an element from stack using two queues.
    int pop()
    {
        if (q1.empty())
            return -1;
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q1.pop();
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return top;
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

    // You are given a stack St of N integers and an element X. You have to insert X at the bottom of the given stack.
    // Without using other data structures
    stack<int> insertAtBottom(stack<int> &st, int x)
    {
        if (st.empty())
            st.push(x);
        else
        {
            int top = st.top();
            st.pop();
            insertAtBottom(st, x);
            st.push(top);
        }
        return st;
    }

    // Function to reverse the stack using recursion.
    void Reverse(stack<int> &st)
    {
        if (st.empty())
            return;
        int top = st.top();
        st.pop();
        Reverse(st);
        insertAtBottom(st, top);
    }

    /* The below method sorts the stack s you are required to complete the below method using recursion*/
    void insertSorted(stack<int> &st, int x)
    {
        if (st.empty() or st.top() <= x)
            st.push(x);
        else
        {
            int top = st.top();
            st.pop();
            insertAtBottom(st, x);
            st.push(top);
        }
    }
    void sort(stack<int> &st)
    {
        if (st.empty())
            return;
        int top = st.top();
        st.pop();
        sort(st);
        insertAtBottom(st, top);
    }

    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long> st;
        vector<long long> left(n, 0), right(n, 0);
        st.push(0);
        left[0] = -1;
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }
        st = stack<long long>();
        st.push(n - 1);
        right[n - 1] = n;
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();
            st.push(i);
        }
        long long ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            long long val = arr[i] * (right[i] - left[i] - 1);
            ans = max(ans, val);
        }
        return ans;
    }

    // Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out
    // the length of the longest valid(well-formed) parentheses substring.
    int findMaxLen(string s)
    {
        stack<int> st;
        int n = s.size();
        int ans = 0;
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                if (!st.empty())
                    ans = max(ans, i - st.top());
                else
                    st.push(i);
            }
        }
        return ans;
    }

    // Given a string of balanced expression, find if it contains a redundant parenthesis or not .
    // A set of parenthesis are redundant if the same sub - expression is surrounded by unnecessary or multiple brackets.
    int checkRedundancy(string s)
    {
        stack<int> st;
        for (char c : s)
        {
            if (c == '(' or c == '+' or c == '-' or c == '*' or c == '/')
                st.push(c);
            else if (c == ')')
            {
                if (!st.empty() and st.top() == '(')
                    return 1;
                while (st.top() != '(')
                    st.pop();
                st.pop();
            }
        }
        return 0;
    }

    // Function to check if array B is a stack permutation of the array A or not.
    int isStackPermutation(int n, vector<int> &A, vector<int> &B)
    {
        stack<int> st;
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            st.push(A[i]);
            if (A[i] == B[ind])
            {
                st.pop();
                ind++;
            }
            while (!st.empty() and st.top() == B[ind])
            {
                st.pop();
                ind++;
            }
        }
        return ind == n;
    }

    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k)
    {
        queue<int> ans;
        stack<int> st;
        while (k--)
        {
            st.push(q.front());
            q.pop();
        }
        while (!st.empty())
        {
            ans.push(st.top());
            st.pop();
        }
        while (!q.empty())
        {
            ans.push(q.front());
            q.pop();
        }
        return ans;
    }
};

int main()
{

    return 0;
}