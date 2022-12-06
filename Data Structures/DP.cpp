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

};

int main(){

    DP dp;

    //cout<<dp.Factorial(13);
    //cout<<dp.nCr(14,3);

    return 0;
}