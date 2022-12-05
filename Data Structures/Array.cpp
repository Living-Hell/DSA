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

    return 0;
}