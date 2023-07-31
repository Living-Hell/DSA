#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the permutation where the student with the most books allocated to him gets
    // the minimum number of pages, out of all possible permutations.
    int pageFinder(int a[], int n, int target)
    {
        int students = 1, pages = 0;
        for (int i = 0; i < n; i++)
        {
            if (pages + a[i] <= target)
                pages += a[i];
            else
            {
                students++;
                pages = a[i];
            }
        }
        return students;
    }
    int findPages(int a[], int n, int m)
    {
        if (m > n)
            return -1;
        int low = INT_MIN, high = 0;
        for (int i = 0; i < n; i++)
        {
            low = max(low, a[i]);
            high += a[i];
        }
        while (low < high)
        {
            int mid = (low + high) / 2;
            int students = pageFinder(a, n, mid);
            if (students > m)
                low = mid + 1;
            else
                high = mid;
        }
        return high;
    }
};