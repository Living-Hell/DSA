#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        next = NULL;
        left = NULL;
        right = NULL;
    }
};

class Heap
{
public:
    int size;
    int hp[100]; // Max size of heap = 100

    Heap()
    {
        size = -1;
    }
    void insert(int x)
    {
        hp[++size] = x;
        int ind = size;
        while (ind > 0)
        {
            int par = (ind - 1) / 2;
            if (hp[par] < hp[ind])
            {

                swap(hp[par], hp[ind]);
                ind = par;
            }
            else
                return;
        }
    }
    void deletee()
    {
        if (size < 0)
        {
            cout << "Heap Underflow" << '\n';
            return;
        }
        hp[0] = hp[size--];
        int ind = 0;
        while (ind < size)
        {
            int lc = (ind * 2) + 1, rc = (ind * 2) + 2;
            if (lc < size and hp[lc] > hp[ind])
            {
                swap(hp[ind], hp[lc]);
                ind = lc;
            }
            else if (rc < size and hp[rc] > hp[ind])
            {
                swap(hp[ind], hp[rc]);
                ind = rc;
            }
            else
                return;
        }
    }

    // Heapify function to maintain heap property.
    void heapify(vector<int> &arr, int n, int i)
    {
        int smallest = i;
        int lc = 2 * i + 1, rc = 2 * i + 2;
        if (lc < n and arr[lc] > arr[smallest])
        {
            smallest = lc;
        }
        if (rc < n and arr[rc] > arr[smallest])
        {
            smallest = rc;
        }
        if (smallest != i)
        {
            swap(arr[smallest], arr[i]);
            heapify(arr, n, smallest);
        }
    }

    // Function to build a Heap from array.
    void buildHeap(vector<int> &arr, int n)
    {
        for (int i = n / 2; i >= 0; i--)
            heapify(arr, n, i);
    }

    // Function to sort an array using Heap Sort.
    void heapSort(vector<int> &arr, int n)
    {
        buildHeap(arr, n);
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }

    void print()
    {
        for (int i = 0; i <= size; i++)
            cout << hp[i] << " ";
        cout << endl;
    }
};

class HeapFuncs
{
public:
    // Function to find K largest elements from the array in decreasing order.
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
            pq.push(arr[i]);
        vector<int> ans;
        while (k--)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }

    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto i : arr)
        {
            for (int j : i)
            {
                pq.push(j);
            }
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }

    // Function to check if the given array represents a Binary Max Heap.
    bool isMaxHeap(int a[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] > a[(i - 1) / 2])
                return 0;
        }
        return 1;
    }

    // Function to convert minHeap to maxHeap
    void MinToMaxHeap(vector<int> &arr, int n, int i)
    {
        int largest = i;
        int lc = 2 * i + 1, rc = 2 * i + 2;
        if (lc < n and arr[lc] > arr[largest])
        {
            largest = lc;
        }
        if (rc < n and arr[rc] > arr[largest])
        {
            largest = rc;
        }
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            MinToMaxHeap(arr, n, largest);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int n)
    {
        for (int i = n / 2; i >= 0; i--)
            MinToMaxHeap(arr, n, i);
    }

    // Function to find the Kth smallest element in the given array
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> pq;
        for (int i = l; i <= r; i++)
        {
            pq.push(arr[i]);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }

    // Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        Heap heap;
        vector<int> ans;
        for (int i : a)
            ans.push_back(i);
        for (int i : b)
            ans.push_back(i);
        heap.buildHeap(ans, n + m);
        return ans;
    }

    // Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++)
        {
            Node *temp = arr[i];
            while (temp != NULL)
            {
                pq.push(temp->data);
                temp = temp->next;
            }
        }
        Node *ans = new Node(-1);
        Node *temp = ans;
        while (!pq.empty())
        {
            temp->next = new Node(pq.top());
            pq.pop();
            temp = temp->next;
        }
        return ans->next;
    }

    // Find the K-th largest sum of contiguous subarray within the array elements.
    int kthLargest(vector<int> &arr, int n, int k)
    {
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                pq.push(sum);
            }
        }
        while (--k and !pq.empty())
        {
            pq.pop();
        }
        return pq.top();
    }

    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < n; i++)
            pq.push(arr[i]);
        long long tcost = 0;
        while (pq.size() > 1)
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long cost = a + b;
            pq.push(cost);
            tcost += cost;
        }
        return tcost;
    }

    // Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree
    // of a node should be less than all the values in the right subtree of the node
    void heapify(Node *root)
    {
        Node *largest = root;
        Node *lc = root->left;
        Node *rc = root->right;
        if (lc and lc->data > largest->data)
            largest = lc;
        if (rc and rc->data > largest->data)
            largest = rc;
        if (largest != root)
            swap(largest->data, root->data);
        if (lc and rc and lc->data > rc->data)
            swap(lc->data, rc->data);
        if (lc)
            heapify(lc);
        if (rc)
            heapify(rc);
    }
    void convertToMaxHeapUtil(Node *root)
    {
        if (!root)
            return;
        convertToMaxHeapUtil(root->right);
        convertToMaxHeapUtil(root->left);
        heapify(root);
    }
};

int main()
{
    Heap heap;
    // heap.insert(69);
    // heap.insert(420);
    // heap.insert(121);
    // heap.insert(323);
    // heap.insert(85);
    // heap.print();
    // heap.deletee();
    // heap.print();
    // int a[8] = {5, 4, 9, 6, 8, 41, 2, 52};
    // heap.heapSort(a, 8);
    // for (int i = 0; i < 8; i++)
    //     cout << a[i] << " ";
    return 0;
}