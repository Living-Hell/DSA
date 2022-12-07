#include<bits/stdc++.h>
using namespace std;

class DP{
public:
    const unsigned int mod = 1000000007;

    long long int factorial(int n){
        long long int fact[n+1] = {0};
        if(n>=0){
            fact[0] = 1;
            for(int i=1; i<=n; i++){
                fact[i] = ((i%mod)*(fact[i-1]%mod))%mod;
            }
            return fact[n];
        }
    }

    long long int nCr(int n, int r){
        
        if(r>n) return 0;

        vector<int> pascal(r+1,0);
        if(r>(n-r)) r = n-r;
        pascal[0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=min(r,i); j>0; j--){
                pascal[j] = (pascal[j] + pascal[j-1])%mod;
            }
        }
        return pascal[r]%mod;
    }

    long long int coinChange(vector<int> coins, int sum) {

        int n = coins.size();
        vector<long long int> dp(sum+1,0);
        dp[0]=1;
        
        for(int i=0; i<n; i++){
            for(int j=coins[i]; j<=sum; j++){
                dp[j] += dp[j-coins[i]];
            }
        }   

        return dp[sum];
    }

    long long int nPr(int n, int r){
        
        if(r>n) return 0;

        vector<int> coeff(n+1,0);
        coeff[0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=min(i,n); j>0; j--){
                coeff[j] = (coeff[j] + (j*coeff[j-1]))%mod;
            }
        }        
        return coeff[r]%mod;
    }

    int knapSack(int W, vector<int> wt, vector<int> val) 
    { 
        int n = wt.size();
        vector<int> vw(W+1,0);
       
        for(int i=0; i<=W; i++){
           if(wt[0]<=i)
            vw[i] = val[0];
        }
       
        for(int i=1; i<n; i++){
           for(int j=W; j>=0; j--){
                if(wt[i] <= j)
                   vw[j] = max(vw[j], val[i] + vw[j-wt[i]]);
            }
        }   
       
       return vw[W];
    }

    int catalan(int n){

        vector<int> catalan(n+1,0);
        catalan[0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                catalan[i] += catalan[j]*catalan[i-j-1];
            }
        }
        
        return catalan[n];
    }

};

int main(){

    DP dp;

    //cout<<dp.Factorial(13);
    //cout<<dp.nCr(14,3);
    //cout<<dp.coinChange({1,2,3},4);
    //cout<<dp.nPr(15,5);
    //cout<<dp.knapSack(4,{4,5,1},{1,2,3});
    //cout<<dp.catalan(19);

    return 0;
}