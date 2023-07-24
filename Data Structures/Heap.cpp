#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    //Function to find K largest elements from the array in decreasing order.
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int> pq;
	    for(int i=0; i<n; i++) pq.push(arr[i]);
	    vector<int> ans;
	    while(k--){
	        ans.push_back(pq.top());
	        pq.pop();
	    }
	    return ans;
	}
};

int main()
{
    Heap heap;
    return 0;
}