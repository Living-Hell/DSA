#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

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

    int knapSack01(int W, vector<int> wt, vector<int> val) 
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

    int LCSof3(string A, string B, string C, int n1, int n2, int n3)
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

    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1,vector<int> (k+1,0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){

                if(j==1)
                    dp[i][j] = 1;                    
                else if(i==1)
                    dp[i][j] = j;                    
                else{
                    int tmax, tmin = INT_MAX;
                    for(int l=0; l<=j; l++){
                        tmax = max(dp[i-1][l],dp[i][j-l-1]);
                        tmin = min(tmin, tmax);
                    }
                    dp[i][j] = tmin+1;
                }
            }
        }
        return dp[n][k];
    }

    int maxSumWO3Consec(vector<int> arr)
    {
        int n = arr.size();
        vector<int> dp(n,0);
        if(n>=1) dp[0] = arr[0];
        if(n>=2) dp[1] = arr[0] + arr[1];
        if(n>2) dp[2] = max(max(dp[1], dp[0] + arr[2]), arr[1] + arr[2]);
        for(int i=3; i<n; i++){
            dp[i] = max(dp[i-1],max(dp[i-2] + arr[i], dp[i-3] + arr[i] + arr[i-1]));
        }
        return dp[n-1];
    }

    static bool lambda(const pair<int,int>& a, const pair<int,int>& b){
        int as = a.second;
        int bf = b.second;
        return(as<bf);
    }
    int maxChainLen(vector<pair<int,int>> p){
        
        int n = p.size();    
        sort(p.begin(), p.end(), lambda);
        vector<int> dp(n,1);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(p[i].first>p[j].second)
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }

    int maxSquare(vector<vector<int>> mat){
        int n = mat.size(), m = mat[0].size();
        int ans=INT_MIN;
        vector<vector<int>> dp(n,vector<int> (m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]>0 && i>0 &&j>0){
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
                }
                else
                    dp[i][j] = mat[i][j];
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }

    int maxSumPairWithDifferenceLessThanK(vector<int> arr, int k)
    {   
        int n = arr.size();
        vector<int> dp(n);
        sort(arr.begin(), arr.end());
        dp[0] = 0;
        
        for(int i=1; i<n; i++){
            dp[i] = dp[i-1];
            if(abs(arr[i-1] - arr[i]) <k){
                if(i==1)
                    dp[i] = max(dp[i], arr[i-1] + arr[i]);
                else
                    dp[i] = max(dp[i], dp[i-2] + arr[i-1] + arr[i]);
            }
        }
        return dp[n-1];
    }

    int maxSubstring(string S)
	{
	    int curr_sum=0, ans=0;
	    int n = S.size();
	    
	    for(int i=0; i<n; i++){
	        if(S[i] == '0')
	            curr_sum++;
	        else 
	            curr_sum--;
	        if(curr_sum<0) curr_sum=0;
	        ans = max(ans,curr_sum);
	    }
	    if(ans==0) return -1;
	    return ans;
	}

    int minJumps(vector<int> arr){
        int n = arr.size();
        vector<int> dp(n,1e7);
        dp[0] = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<min(n,arr[i]+i+1); j++)
                dp[j] = min(dp[j], dp[i] + 1);
        }
        if(dp[n-1] == 1e7) return -1;
        return dp[n-1];
    }

    int minimumCost(vector<int> cost, int w) 
	{ 
        int n = cost.size();
        vector<int> dp(w+1,INT_MAX);
        dp[0]=0;
        
        for(int i=1; i<=w; i++){
            for(int j=0; j<min(n,i); j++){
                if(cost[j] != -1 && dp[i-j-1] != INT_MAX){
                    dp[i] = min(dp[i], cost[j]+dp[i-j-1]);
                }
            }
        }
        return dp[w] == INT_MAX? -1 : dp[w];
	} 

    int longestCommonSubstr(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        int ans=0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }

    long long int reachScore(long long int n)
    {
        vector<long long int> dp(n+1,0);
        int scores[3] = {3,5,10};
        dp[0] = 1;
        
        for(int i=0; i<=2; i++){
            for(int j=scores[i]; j<=n; j++){
                dp[j] += dp[j-scores[i]]; 
            }
        }        
        return dp[n];
    }

    long long int countBT(int h) 
    { 
        long long int dp[h+1];
        dp[0] = 1; dp[1] = 1;
        for(int i=2; i<=h; i++){
            dp[i] = (dp[i-1] * (dp[i-1] + 2*dp[i-2]))%mod;
        }
        return dp[h];
    }

    long long maxSubarraySum(vector<int> arr)
    {    
        int n = arr.size();    
        long long int ans = arr[0], curr_sum=0;
        
        for(int i=0; i<n; i++){
            curr_sum += arr[i];
            ans = max(ans,curr_sum);
            if(curr_sum<0) curr_sum=0;
        }
        return ans;
    }

    int knapSackUnbounded(int w, vector<int> val, vector<int> wt)
    {
        int n = val.size();
        vector<int> dp(w+1,0);
        dp[0]=0;
        
        for(int i=1; i<=w; i++){
            for(int j=0; j<n; j++){
                if(wt[j]<=i)
                    dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
            }
        }
        return dp[w];
    }

    int wordBreak(string a, vector<string> b) {
        int n = a.size();
        vector<int> dp(n+1, 0);
        dp[0]=1;
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                string sub1 = a.substr(j,i-j);
                if(find(b.begin(),b.end(),sub1)!=b.end() && dp[j]==1){
                    dp[i]=1;
                }
            }
        }
        return dp[n];
    }

    long long int countPS(string str)
    {
        int n= str.size();
        vector<vector<long long int>> dp(n, vector<long long int> (n,0));
        long long int ans=0;
        
        for(int i=0; i<n; i++)
                dp[i][i] = 1;
        
        for(int i=1; i<n; i++){
            for(int j=0; i+j<n; j++){
                if(str[j] == str[j+i]){
                   dp[j][i+j] = (1 + dp[j][i+j-1] + dp[j+1][i+j])%mod; 
                }
                else{
                    dp[j][i+j] = (mod + dp[j][i+j-1] + dp[j+1][i+j] - dp[j+1][i+j-1])%mod; 
                }
            }
        }  
        return dp[0][n-1]%mod;       
    }

    int AlternatingaMaxLength(vector<int> nums){
        int n = nums.size();
        int incr = 1, decr = 1;
        
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1])
                incr = decr + 1;
            else if(nums[i]<nums[i-1])
                decr = incr + 1;
        }
        return max(incr,decr);
	}

    //Gives TLE after 100(/110) test cases
    /*int AlternatingaMaxLength(vector<int>&nums){
        int n = nums.size();
        vector<vector<int>> dp (n, vector<int> (2,1));
        int ans=1;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j])
                    dp[i][1] = max(dp[j][0]+1, dp[i][1]);
                else if(nums[i]<nums[j])
                    dp[i][0] = max(dp[j][1]+1, dp[i][0]);
                ans = max(ans,max(dp[i][1],dp[i][0]));
            }
            ans = max(ans,max(dp[i][1],dp[i][0]));
        }
        return ans;
    }*/

    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, [] (Job a, Job b) {return a.profit>b.profit;});
        vector<int> greedy(n,0);
        
        for(int i=0; i<n; i++){
            for(int j = arr[i].dead-1; j>=0; j--){
                if(greedy[j] == 0){
                    greedy[j] = arr[i].profit;
                    break;
                }
            }
        }  
        int count=0 , ans=0;
        for(int i=0; i<n; i++){
            if(greedy[i]!=0){
                count++;
                ans+=greedy[i];
            }
        } 
        return {count,ans};
    } 

    long long maximumAmount(vector<int> arr){
        int n = arr.size();
        vector<vector<long long>> dp(n,vector<long long>(n,0));
        
        for(int i=0; i<n; i++){
            dp[i][i] = arr[i];
            dp[i][i+1] = max(arr[i],arr[i+1]);
        }
        
        for(int gap=2; gap<n; gap++){
            for(int i=0, j=gap; j<n; j++,i++){
                long long front = arr[j] + min(dp[i+1][j-1], dp[i][j-2]);
                long long back = arr[i] + min(dp[i+1][j-1], dp[i+2][j]);
                dp[i][j] = max(front,back);
            }
        }        
        return dp[0][n-1];
    }

    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int> (n,0));
        
        for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; j++, i++){
                if(gap==0) 
                    dp[i][j]=1;
                else if(gap==1){
                    if(str[j] == str[j-1])
                        dp[i][j] = 1;
                    else
                        dp[i][j]=0;
                }
                else{
                    if(str[j] == str[i])
                        dp[i][j] = dp[i+1][j-1];
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
        
        vector<int> cuts(n,0);
        cuts[0] = 0;
        
        if(str[1] == str[0]) cuts[1] = 0;
        else cuts[1] = 1;
        
        for(int i=2; i<n; i++){
            if(dp[0][i]){
                cuts[i] = 0;
                continue;
            }
            int ans=INT_MAX;
            for(int j=0; j<=i; j++){
                if(dp[j][i]){
                    ans = min(ans,1 + cuts[j-1]);
                }
            }
            cuts[i] = ans;
        }
        return cuts[n-1];
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        vector<int> dp(n+1,INT_MAX);
        int ans=INT_MAX, last_sentence=0;
        
        dp[0] = 0;
        dp[1] = pow((k-nums[0]),2);
        
        
        for(int i=2; i<=n; i++){
            int sum = 0, count=0;
            for(int j=i; j>=1; j--){
                count++;
                sum+= nums[j-1];
                if(count>1) sum++;
                if(sum>k) break;
                int cost = dp[j-1] + pow((k-sum),2);
                dp[i] = min(dp[i], cost);
            }
        }
        
        int sum = 0, count=0;
        for(int j=n; j>=1; j--){
                count++;
                sum+= nums[j-1];
                if(count>1) sum++;
                if(sum>k) break;
                int cost = dp[j-1];
                ans = min(ans, cost);
            }
        return ans;
    } 

    int booleanParenthesis(string s){
        int n = s.size();
        int m = (n+1)/2;
        vector<vector<int>> dpt(m, vector<int>(m,0)), dpf(m, vector<int>(m,0));
        
        for(int g=0; g<m; g++){
            for(int i=0, j=g; j<m; i++, j++){
                if(g==0){
                    if(s[j*2] == 'T'){ 
                        dpt[i][j] = 1;
                        dpf[i][j] = 0;
                    }
                    else if(s[j*2] == 'F'){ 
                        dpf[i][j] = 1;
                        dpt[i][j] = 0;
                    }
                }
                else{
                    for(int k=i; k<j; k++){
                        if(s[(2*k)+1] == '&'){
                        dpt[i][j] += (dpt[i][k] * dpt[k+1][j])%1003;
                        dpf[i][j] += (dpf[i][k] * (dpf[k+1][j] + dpt[k+1][j]))%1003;
                        dpf[i][j] += (dpt[i][k] * dpf[k+1][j])%1003;
                        }
                        else if(s[(2*k)+1] == '|'){ 
                            dpt[i][j] += (dpt[i][k] * (dpt[k+1][j] + dpf[k+1][j]))%1003;
                            dpt[i][j] += (dpf[i][k] * dpt[k+1][j])%1003;
                            dpf[i][j] += (dpf[i][k] * dpf[k+1][j])%1003; 
                        }
                        else if(s[(2*k)+1] == '^'){
                            dpt[i][j] += (dpt[i][k] * dpf[k+1][j])%1003;
                            dpf[i][j] += (dpt[i][k] * dpt[k+1][j])%1003;
                            dpt[i][j] += (dpf[i][k] * dpt[k+1][j])%1003; 
                            dpf[i][j] += (dpf[i][k] * dpf[k+1][j])%1003;
                        }
                    }
                }
            }
        }
        return dpt[0][m-1]%1003;
    }

    long long helperMobileKeypad(int i, int j, int n, vector<vector<long long>> &dp, vector<vector<int>> v){
        if(i<0 || j<0 || i>=4 || j>=3 || v[i][j] == -1) return 0;
        if(n==0){
            return 1;
        }
        
        if(dp[v[i][j]][n]>0) return dp[v[i][j]][n];
        long long temp=0;
        temp+= helperMobileKeypad(i-1,j,n-1,dp,v);
        temp+= helperMobileKeypad(i+1,j,n-1,dp,v);
        temp+= helperMobileKeypad(i,j-1,n-1,dp,v);
        temp+= helperMobileKeypad(i,j+1,n-1,dp,v);
        temp+= helperMobileKeypad(i,j,n-1,dp,v);
        
        return dp[v[i][j]][n] = temp;
    }
	long long getCountMNK(int n)
	{   
	    vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
	    vector<vector<long long>> dp(12,vector<long long>(n,0));
        long long ans=0;
	    
		for(int i=0; i<4; i++){
		    for(int j=0; j<3; j++){
		        if(v[i][j]==-1) continue;
                ans+= helperMobileKeypad(i,j,n-1, dp, v);
		    }
		}
		return ans;
	}

    int kadaneAlgo(vector<int> v){
        int curr_sum=v[0], max_sum=v[0];
        for(int i=1; i<v.size(); i++){
            if(curr_sum<=0) curr_sum = v[i];
            else curr_sum += v[i];
            if(curr_sum>max_sum) max_sum = curr_sum;
        }
        return max_sum;
    }
    int maximumSumRectangle(vector<vector<int>> m) {
        int r = m.size(), c = m[0].size();
        int ans=INT_MIN;
        for(int k=0; k<r; k++){
            vector<int>  temp(c,0);
            for(int i=k; i<r; i++){
                for(int j=0; j<c; j++){
                    temp[j] += m[i][j];
                }
                int t_sum = kadaneAlgo(temp);
                ans = max(ans,t_sum);
            }
        }
        return ans;
    }

    int dpIS[101][101];
    int helperIS(string a, string b, string c, int i, int j, int k){
        if(k==c.size()) return true;
        if(dpIS[i][j] != -1) return dpIS[i][j];
        
        bool flag1 = false, flag2 = false;
        
        if(i<a.size()){
            if(c[k] == a[i])
                flag1 = helperIS(a,b,c,i+1,j,k+1);
        }
        if(j<b.size()){
            if(c[k] == b[j])
                flag2 = helperIS(a,b,c,i,j+1,k+1);
        }
        return dpIS[i][j] = flag1 | flag2;
    }    
    bool isInterleave(string A, string B, string C) 
    {
        if(C.size() != B.size() + A.size()) 
            return false;
        memset(dpIS,-1,sizeof(dpIS));
        return helperIS(A,B,C,0,0,0) == 1;
    }

    int maxProfit(int k, vector<int> a) {
        int n = a.size();
        vector<vector<int>> dp(k+1, vector<int>(n,0));
        
        for(int i=1; i<=k; i++){
            int mx = INT_MIN;
            for(int j=1; j<n; j++){
                mx = max(mx, dp[i-1][j-1] - a[j-1]);
                dp[i][j] = max(mx+a[j], dp[i][j-1]);
            }
        }
        return dp[k][n-1];
    }

    int maximalRectangle(vector<vector<int>> matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n,0), left(n,0), right(n,n);
        int ans = INT_MIN;

        for(int i=0; i<m; i++){
            int curr_left=0, curr_right=n;
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1) dp[j]++;
                else dp[j] = 0;
            }            
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1) left[j] = max(curr_left, left[j]);
                else {
                    curr_left = j+1;
                    left[j] = 0;
                }
            }            
            for(int j=n-1; j>=0; j--){
                if(matrix[i][j] == 1) right[j] = min(curr_right, right[j]);
                else {
                    curr_right = j;
                    right[j] = n;
                }
            }
            int temp=INT_MIN;
            for(int j=0; j<n; j++){
                temp = max(temp, dp[j] * (right[j] - left[j]));
            }
            ans = max(ans,temp);
        }
        return ans;
    }

    int longestValidParentheses(string s) {
        int n = s.size(); if(n==0) return 0;
        vector<int> dp(n,0);

        for(int i=1; i<n; i++){
            if(s[i] == ')'){
                int prev_left = i-1-dp[i-1];
                if(prev_left>=0 && s[prev_left] == '('){
                    dp[i] = dp[i-1] + 2;
                    if(prev_left>0){
                        dp[i] += dp[prev_left-1];
                    }
                }
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
    //cout<<dp.longestSubsequence({10, 9, 4, 5, 4, 8, 6});
    //cout<<dp.eggDrop(3,7);
    //cout<<dp.maxSumWO3Consec({3000, 2000, 1000, 3, 10});
    //cout<<dp.maxChainLen({{5, 24} ,{39, 60} , {15, 28} ,{ 27, 40} , {50, 90}});
    //cout<<dp.maxSquare({{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}});
    //cout<<dp.maxSumPairWithDifferenceLessThanK({3,5,10,15,17,12,9},4);
    //cout<<dp.maxSubstring("11000010001");
    //cout<<dp.minJumps({1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9});
    //cout<<dp.minimumCost({20,10,4,50,100},5);
    //cout<<dp.longestCommonSubstr("ABCSDDF","ADVDFVBCBF");
    //cout<<dp.reachScore(20);
    //cout<<dp.countBT(6);
    //cout<<dp.maxSubarraySum({-1,-2,5,4,-6,2});
    //cout<<dp.knapSackUnbounded(8,{1, 4, 5, 7},{1, 3, 4, 5});
    //cout<<dp.wordBreak("vvdiidtlrvwngfexqdkkpfyjteqkvdbocfexqdkkpfvvdiidtlejacyjteqkvdbo", {"rvwng", "lben", "tztspyafeu", "ejac", "fexqdkkpf", "yjteqkvdbo", "ffbwkmzaw", "vvdiidtl", "c", "zhw"});
    //cout<<dp.countPS("abccbc");
    //cout<<dp.AlternatingaMaxLength({1,17,5,10,13,15,10,5,16,8});
    //cout<<dp.maximumAmount({6335,2103,3929,7359,587,1551,3341,1060});
    //cout<<dp.palindromicPartition("ababbbabbababa");
    //cout<<dp.solveWordWrap({3,2,2,5},6);
    //cout<<dp.booleanParenthesis("T&T|F|F^F^T^T^T&T^F^T&F|F^F^F&F&F|F|F^F^T|T&T");
    //cout<<dp.getCountMNK(4);
    //cout<<dp.maximumSumRectangle({{1,2,-1,-4,-20},{-8,-3,4,2,1},{3,8,10,1,3},{-4,-1,1,7,-6}});
    //cout<<dp.isInterleave("XY", "X", "XYX");
    //cout<<dp.maxProfit(2,{10,22,5,75,65,80});
    //cout<<dp.maximalRectangle({{0, 1, 1, 0},{1, 1, 1, 1},{1, 1, 1, 1},{1, 1, 0, 0}});
    //cout<<dp.longestValidParentheses("()(())()())()()");

    return 0;
}