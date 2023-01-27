//To find all possible paths that the rat can take to reach from source(0,0) to destination(n-1,n-1)
//No cell can be visited more than one time.

class Solution{
    public:
    void helper(int i, int j, vector<string> &ans, string curr, int n, vector<vector<int>> m, vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>n-1 || j>n-1 || m[i][j]==0 || visited[i][j])
            return;
        
        if(i==n-1 && j==n-1){
            ans.push_back(curr);
            return;
        }
            
        visited[i][j] = 1;
        
        helper(i+1,j,ans,curr+"D",n,m,visited);
        helper(i-1,j,ans,curr+"U",n,m,visited);
        helper(i,j+1,ans,curr+"R",n,m,visited);
        helper(i,j-1,ans,curr+"L",n,m,visited);
        
        visited[i][j] = 0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        vector<string> ans;
        helper(0,0,ans,"",n, m,visited);
        return ans;
    }
};