#include<bits/stdc++.h>
using namespace std;

class Array{
public:

    //Function to reverse a given array
    vector<int> Reversal(vector<int> v){
        int n = v.size();

        for(int i=0; i<n/2; i++){
            int temp = v[i];
            v[i] = v[n-i-1];
            v[n-i-1] = temp; 
        }

        return v;
    }

    //Function to find the Minimum and Maximum value in the array
    void MaxMin(vector<int> v){

        int n = v.size();
        int min = INT_MAX, max = INT_MIN;

        for(int i=0; i<n; i++){
            if(v[i]>max) max = v[i];
            if(v[i]<min) min = v[i];
        }

        cout<<"Minimum value is : "<<min<<endl<<"Maximum value is : "<<max<<endl;
    }

    //To Find the kth smallest element in array
    int kthSmallest(vector<int> v, int k) {
        
        int n = v.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<n; i++) pq.push(v[i]);
        while(--k) pq.pop();
        
        return pq.top();
    }

    //To sort array containing 0,1,2
    vector<int> sort012(vector<int> arr)
    {
        int n = arr.size();
        int count0 = 0, count1 = 0, count2 = 0;

        for(int i=0; i<n; i++){
            if(arr[i] == 0) count0++;
            else if(arr[i] == 1) count1++;
            else count2++;
        }
        
        for(int i=0; i<count0; i++) arr[i] = 0;
        for(int i=count0; i<count0+count1; i++) arr[i] = 1;
        for(int i=count0+count1; i<n; i++) arr[i] = 2;

        return arr;
    }

    //To find Pairs with specific difference
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        int ans = 0;
        sort(arr, arr+n, greater<int>());
        
        for(int i=1; i<n; i++){
            if(arr[i-1] - arr[i] < k){
                ans+= arr[i] + arr[i-1];
                i++;
            }
        }
        
        return ans;
    }

    //To print the array
    void print(vector<int> v){
        for(int i=0; i<v.size(); i++) 
            cout<<v[i]<<" ";
        cout<<endl;
    }

};

int main(){

    cout<<"Size : ";
    int n; cin>>n;

    cout<<"Array : ";
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    Array a;
    //a.print(a.Reversal(v));   
    //a.MaxMin(v);

    return 0;
}