#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};

class Solution{
public:
    static bool lambda(const val& a, const val& b){
        int as = a.second;
        int bf = b.second;
        return(as<bf);
    }
    int maxChainLen(struct val p[],int n){
        
        sort(p, p+n, lambda);
        vector<int> dp(n,1);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(p[i].first>p[j].second)
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}