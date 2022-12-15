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

        //Cn = sum[i=0:n](Ci*Cn-i)
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

    int editDistance(string s, string t) {
        
        int slen = s.size(), tlen = t.size();
        vector<vector<int>> v(slen+1, vector<int> (tlen+1,0));
        
        for(int i=0; i<=slen; i++) v[i][0] = i;
        for(int i=0; i<=tlen; i++) v[0][i] = i;
        
        for(int i=1; i<=slen; i++){
            for(int j=1; j<=tlen; j++){
                
                if(s[i-1] == t[j-1]) v[i][j] = v[i-1][j-1];
                
                else if(s[i-1] != t[j-1]){
                    int top = v[i-1][j];
                    int left = v[i][j-1];
                    int tleft = v[i-1][j-1];
                    v[i][j] = min(min(top,left),tleft) + 1;
                
                } 
            }
        }        
        return v[slen][tlen];
    }

    int matrixChainMultiplication(vector<int> dim){
        int n = dim.size();
        vector<vector<int>> v(n,vector<int> (n,INT_MAX));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){ 
                if((i+j)>=n) continue;
                if(i==0){
                    v[j][i+j] = 0;
                    continue;
                }
                for(int k=j; k<i+j; k++){
                    v[j][i+j] = min(v[j][i+j],
                                    (v[j][k] + v[k+1][i+j] + dim[j-1]*dim[k]*dim[i+j]));
                }
            }
        }
        return v[1][n-1];
    }

    long long countWays(int n, int k){
        vector<vector<long long>> ways(3,vector<long long> (n,0));
        ways[0][0] = ways[1][0] = ways[2][0] = k;
        
        for(int i=1; i<n; i++){
            long long prevd = ways[1][i-1]%mod;
            long long prevt = ways[2][i-1]%mod;
            ways[0][i] = prevd;
            ways[1][i] = (prevt * (k-1))%mod;
            ways[2][i] = (ways[0][i] + ways[1][i])%mod;
        }        
        return ways[2][n-1];
    }

    //Function to find the maximum number of cuts.
    int helper(int sum, int x, int y, int z, int s[]){      

        if(sum==0) return 0;            
        if(s[sum] != -1) return s[sum];   

        int t1=INT_MIN,t2=INT_MIN,t3=INT_MIN;
        
        if(sum>=x) t1 = helper(sum-x, x,y,z,s);
        if(sum>=y) t2 = helper(sum-y, x,y,z,s);
        if(sum>=z) t3 = helper(sum-z, x,y,z,s);

        return s[sum] = 1+max(max(t1,t2),t3);        
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {   
        int s[10005];
        memset(s,-1,sizeof(s));
        int ret = helper(n,x,y,z,s);
        if(ret <0 ) return 0;
        return ret;
    }

    int lcs(string s1, string s2)
    {
        int x = s1.size(), y = s2.size();
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        
        for(int i=1; i<=x; i++){
            for(int j=1; j<=y; j++){
                if(i>0 && j>0){
                    if(s1[i-1] == s2[j-1])
                        dp[i][j] = dp[i-1][j-1]+1;
                    else
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
    }

    int LongestRepeatingSubsequence(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i>0 && j>0){
                    if(s[i-1] == s[j-1] && i!=j)
                        dp[i][j] = dp[i-1][j-1]+1;
                    else
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }

    int lengthOfLIS(vector<int> nums) 
    {
        int n = nums.size();
        vector<int> dp(n,1);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end()); 
    }

    int maxSumIS(vector<int> arr)  
	{  
        int n = arr.size();
        vector<int> dp(n);
        for(int i=0; i<n; i++) dp[i] = arr[i];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i]>arr[j])
                    dp[i] = max(dp[i], dp[j]+arr[i]);
            }
        }
        return *max_element(dp.begin(),dp.end()); 
	}

    int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
    {
        vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));
        
        for(int i=0; i<=n1; i++){
            for(int j=0; j<=n2; j++){
                for(int k=0; k<=n3; k++){
                    if(i==0 || j==0 || k==0) 
                        dp[i][j][k] = 0;
                    else if(A[i-1] == B[j-1] && B[j-1] == C[k-1])
                        dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                    else
                        dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
                }
            }
        }
        return dp[n1][n2][n3];
    }

    int longestSubsequence(vector<int> nums) 
    {
        int n = nums.size();
        vector<int> dp(n,1);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(abs(nums[i]-nums[j])==1)
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
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
    //cout<<dp.editDistance("geek", "gesek");
    //cout<<dp.matrixChainMultiplication({1, 2, 3, 4, 3});
    //cout<<dp.countWays(5000,100);
    //cout<<dp.maximizeTheCuts(4,2,2,1);
    //cout<<dp.lcs("ABCDGH", "AEDFHR");
    //cout<<dp.LongestRepeatingSubsequence("jdzkvjkzcnvkjxcvnkjzczvjk");
    //cout<<dp.lengthOfLIS({5,2,3,5,4,5,4,4,5,22,1,5,6,2});
    //cout<<dp.maxSumIS({52, 12, 656, 65, 121, 1233, 48});
    //cout<<dp.LCSof3("geeks", "geeksfor", "geeksforgeeks", 5, 8, 13);
    cout<<dp.longestSubsequence({10, 9, 4, 5, 4, 8, 6});

    return 0;
}