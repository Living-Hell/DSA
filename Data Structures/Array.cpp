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

    void MaxMin(vector<int> v){

        int n = v.size();
        int min = INT_MAX, max = INT_MIN;

        for(int i=0; i<n; i++){
            if(v[i]>max) max = v[i];
            if(v[i]<min) min = v[i];
        }

        cout<<"Minimum value is : "<<min<<endl<<"Maximum value is : "<<max<<endl;

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
    a.MaxMin(v);

    return 0;
}