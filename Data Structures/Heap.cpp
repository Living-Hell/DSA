#include <bits/stdc++.h>
using namespace std;

class Heap
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
};

int main()
{
    Heap heap;
    return 0;
}