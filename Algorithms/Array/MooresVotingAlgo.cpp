#include <bits/stdc++.h>
using namespace std;

// Function to find majority element in the array using Moore's Voting Algorithm
int majorityElement(int a[], int size)
{
    int count = 0, el;
    for (int i = 0; i < size; i++)
    {
        if (count == 0)
        {
            el = a[i];
            count++;
        }
        else if (a[i] != el)
            count--;
        else
            count++;
    }
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == el)
            count++;
        if (count > size / 2)
            return el;
    }
    return -1;
}