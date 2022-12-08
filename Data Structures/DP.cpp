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

    int equalPartition(vector<int> nums) {
        int N = nums.size();

        int tsum = accumulate(nums.begin(),nums.end(), 0);
        if(tsum%2==1) return 0;
        
        tsum/=2;
        vector<int> sum(tsum+1,0);
        sum[0] = 1;
        for(int i=0; i<N; i++){
            for(int j=tsum; j>=nums[i]; j--){
                if(sum[j-nums[i]] == 1)
                    sum[j] = 1;
            }   
        }
        return sum[tsum];
    }

    int countFriendsPairings(int n) 
    {   
        //Cn = Cn-2 * (n-1) + Cn-1
        vector<long long int> pair(n+1);        
        pair[0] = 1; pair[1] = 1;
        
        for(int i=2; i<=n; i++){
            pair[i] = ((pair[i-2]%mod*(i-1)%mod)%mod + pair[i-1]%mod)%mod;
        }        
        return pair[n];
    }

    int maxGold(vector<vector<int>> M)
    {   
        int n = M.size(), m = M[0].size();

        for(int j=m-2; j>=0; j--){
            for(int i=0; i<n; i++){
                
                int rup = 0;
                if(i>0) rup = M[i-1][j+1];
                
                int r = M[i][j+1];
                
                int rdwn = 0;
                if(i<n-1) rdwn = M[i+1][j+1];
                
                M[i][j] += max(max(r,rdwn),rup);
            }
        }

        int ans=0;
        for(int i=0; i<n; i++) ans = max(ans, M[i][0]);
        return ans;
    }

    int maximumPath(vector<vector<int>> Matrix)
    {   
        int N = Matrix.size();

        for(int i=N-2; i>=0; i--){
            for(int j=0; j<N; j++){
                int down = 0, rdown = 0, ldown = 0;

                if(j>0) ldown = Matrix[i+1][j-1];
                if(j<N-1) rdown = Matrix[i+1][j+1];
                down = Matrix[i+1][j];

                Matrix[i][j] += max(max(rdown,ldown),down);
            }
        }
                
        int ans=0;
        for(int i=0; i<N; i++) ans = max(ans, Matrix[0][i]);
        return ans;
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
    //cout<<dp.equalPartition({1,655,43,5,45,32,654,65,54,562,1});
    //cout<<dp.countFriendsPairings(10000);
    //cout<<dp.maxGold({{1, 3, 1, 5},{2, 2, 4, 1},{5, 0, 2, 3},{0, 6, 1, 2}});
    //cout<<dp.maximumPath({{348, 391},{618, 193}});

    return 0;
}