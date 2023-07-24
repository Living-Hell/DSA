#include <bits/stdc++.h>
using namespace std;

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
    void heapify(int arr[], int n, int i)
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
    void buildHeap(int arr[], int n)
    {
        for (int i = n / 2; i >= 0; i--)
            heapify(arr, n, i);
    }

    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
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