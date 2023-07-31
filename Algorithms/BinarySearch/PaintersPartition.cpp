#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Find the minimum time to get this job done if all painters start together with the constraint that
    // any painter will only paint continuous boards
    int minmTime(int arr[], int n, int area)
    {
        int painters = 1, tarea = 0;
        for (int i = 0; i < n; i++)
        {
            if (tarea + arr[i] <= area)
                tarea += arr[i];
            else
            {
                painters++;
                tarea = arr[i];
            }
        }
        return painters;
    }
    long long minTime(int arr[], int n, int k)
    {
        int low = INT_MIN;
        long long high = 0;

        for (int i = 0; i < n; i++)
        {
            low = max(low, arr[i]);
            high += arr[i];
        }

        while (low < high)
        {
            long mid = (low + high) / 2;
            int painters = minmTime(arr, n, mid);
            if (painters > k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};