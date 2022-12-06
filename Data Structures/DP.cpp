#include<bits/stdc++.h>
using namespace std;

class DP{
public:
    const unsigned int mod = 1000000007;

    long long int Factorial(int n){
        long long int factorial[n+1] = {0};
        if(n>=0){
            factorial[0] = 1;
            for(int i=1; i<=n; i++){
                factorial[i] = ((i%mod)*(factorial[i-1]%mod))%mod;
            }
            return factorial[n];
        }
    }

    long long int nCr(int n, int r){
        
        if(r>n) return -1;
        
        vector<vector<long long int>> pascal(1000);
        pascal[0].push_back(1); pascal[0].push_back(0);

        for(int i=1; i<1000; i++){
            pascal[i].push_back(1);
            for(int j=1; j<pascal[i-1].size(); j++){
                pascal[i].push_back((pascal[i-1][j-1]%mod + pascal[i-1][j]%mod)%mod);
            }
            pascal[i].push_back(0);
        }
        return pascal[n][r]%mod;
    }

};

int main(){

    DP dp;

    //cout<<dp.Factorial(13);
    //cout<<dp.nCr(14,3);

    return 0;
}