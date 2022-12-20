#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minJumps(int arr[], int n){
        int maxReach = arr[0], steps = arr[0], jumps = 1;
        
        if(n==1) return 0;
        if(arr[0] == 0) return -1;
        
        for(int i=1; i<n-1; i++){
            maxReach = max(maxReach,i+arr[i]);
            steps--;
            if(steps==0){
                jumps++;
                if(i>= maxReach) return -1;
                steps = maxReach-i;
            }
        }
        return jumps;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}