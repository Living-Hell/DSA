static bool lambda(const pair<int,int>& a, const pair<int,int>& b){
        int as = a.second;
        int bf = b.second;
        return(as<bf);
    }
int maxChainLen(vector<pair<int,int>> p){
    
    int n = p.size();
    sort(p.begin(), p.end(), lambda);
    int ans=0, curr_as=INT_MIN;
    
    for(int i=0; i<n; i++){
        if(curr_as<p[i].first){
            ans++;
            curr_as = p[i].second;
        }
    }
    return ans;
}