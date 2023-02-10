#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> size, rank, parent;
    
    DisjointSet(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i]=i;
    }

    int findPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void UnionByRank(int u, int v){
        int upr_u = findPar(u);
        int upr_v = findPar(v);

        if(upr_u == upr_v)  return;

        if(rank[upr_u] < rank[upr_v]){
            parent[upr_u] = upr_v;
        }
        else if(rank[upr_u] > rank[upr_v]){
            parent[upr_v] = upr_u;
        }
        else{
            parent[upr_u] = upr_v;
            rank[upr_v]++;
        }
    }

    void UnionBySize(int u, int v){
        int upr_u = findPar(u);
        int upr_v = findPar(v);

        if(upr_u == upr_v) return;

        if(size[upr_u] > size[upr_v]){
            parent[upr_v] = upr_u;
            size[upr_u] += size[upr_v];
        }
        else{
            parent[upr_u] = upr_v;
            size[upr_v] += size[upr_u];
        }
    }
};

class Graph{
public:
    unordered_map<int, list<pair<int,int>>> adjlist;

    struct Node {
        int val;
        vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    };

    // Function to add an edge in a Grpah
    void addEdge(int u, int v, int dist, bool undirected = 1){
        adjlist[u].push_back(make_pair(v,dist));
        if(undirected)
            adjlist[v].push_back(make_pair(u,dist));
    }

    //Function to print the adjacency list of Graph
    void print_adj(){
        for(auto i : adjlist){
            cout<<i.first<<" : ";
            for(auto j : i.second){
                cout<<"( "<<j.first<<" , "<<j.second<<" ) ";
            }
            cout<<endl;
        }
    }

    //Find any Topological Sorting of the Directed Acyclic Graph (DAG) with V vertices and E edges.
    //Using Kahn's Algorithm
    vector<int> topoSort(int v, vector<vector<int>> adj) {
	    vector<int> indegree(v,0),ans;
	    queue<int> q;
	    
	    for(int i=0; i<v; i++){
	        for(int j:adj[i]){
	            indegree[j]++;
	        }
	    }
	    for(int i=0; i<v; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    while(!q.empty()){
	        int top = q.front();
	        q.pop();
	        ans.push_back(top);
	        
	        for(int i:adj[top]){
	            indegree[i]--;
	            if(indegree[i] == 0)
	                q.push(i);
	        }
	    }
	    return ans;
	}
    
    // Function for BFS Traversal of a Graph
    vector<int> BFSTraversal(int v, vector<vector<int>> adj) {
        vector<int> bfs;
        vector<bool> visited(v,0);
        queue<int> q;
        
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(int i:adj[top]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }
            bfs.push_back(top);
        }
        return bfs;
    }

    // Function for DFS Traversal of a Graph
    vector<int> DFSTraversal(int v, vector<vector<int>> adj) {
        vector<int> dfs;
        vector<bool> visited(v,0);
        stack<int> st;
        st.push(0);
        
        while(!st.empty()){
            int top = st.top();
            st.pop();

            if(!visited[top]){
                visited[top]=1;
                dfs.push_back(top);
            }
            else 
                continue;    

            for(int i=adj[top].size()-1; i>=0; i--){
                if(!visited[adj[top][i]]){
                    st.push(adj[top][i]);
                }
            }
        }
        return dfs;
    }
    
    // Function to detect cycle in an undirected graph using DFS.
    bool DFSCycleUndirected(int node, int parent, vector<bool> &visited, vector<int> adj[]){
        visited[node] = 1;        
        for(int i:adj[node]){
            if(i!=parent && visited[i]) return true;
            if(!visited[i]) if(DFSCycleUndirected(i,node,visited,adj)) return true;
        }
        return false;
    }
    bool isCycleUndirected(int v, vector<int> adj[]) {
        vector<bool> visited(v,0);        
        for(int i=0; i<v; i++){
            if(!visited[i]){
                if(DFSCycleUndirected(i,-1, visited, adj)) 
                    return 1;
            }
        }
        return 0;
    }

    // Function to detect cycle in a directed graph using DFS.
    bool dfsCycleDirected(int node, vector<bool> &visited, vector<bool> &dfsVisited, vector<int> adj[]){
        dfsVisited[node] = visited[node] = 1;
        for(int i:adj[node]){
            if(!visited[i]){
                if(dfsCycleDirected(i,visited,dfsVisited, adj))
                    return true;
            }
            else if(visited[i] && dfsVisited[i])
                return true;
            else if(visited[i] && !dfsVisited[i])
                continue;
        }
        dfsVisited[node] = 0;
        return false;
    }
    bool isCyclicDirected(int v, vector<int> adj[]) {
        vector<bool> visited(v,0), dfsVisited(v,0);
        for(int i=0; i<v; i++){
            if(!visited[i])
                if(dfsCycleDirected(i,visited,dfsVisited,adj))
                    return true;
        }
        return false;
    }

    // Function to detect cycle in a directed graph using BFS - Kahn's Algorithm
    bool isCyclicDirectedBFS(int v, vector<int> adj[]) {
        vector<int> indegree(v,0),ans;
	    queue<int> q;	    
	    for(int i=0; i<v; i++){
	        for(int j:adj[i]){
	            indegree[j]++;
	        }
	    }
	    for(int i=0; i<v; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    int count=0;
	    while(!q.empty()){
	        int top = q.front();
	        q.pop();
	        ans.push_back(top);
	        count++;	        
	        for(int i:adj[top]){
	            indegree[i]--;
	            if(indegree[i] == 0)
	                q.push(i);
	        }
	    }
	    return !(count==v);
    }

    //To find out the minimum steps a Knight will take to reach the target position in a square chessboard.
    int minStepToReachTarget(vector<int>KnightPos,vector<int>TargetPos,int n)
	{   
	    if(KnightPos == TargetPos) return 0;

	    vector<pair<int,int>> moves = {{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
	    int indi = KnightPos[0]-1 , indj = KnightPos[1]-1,  tari = TargetPos[0]-1, tarj = TargetPos[1]-1;
	    
        queue<vector<int>> q;
	    vector<vector<bool>> vis(n,vector<bool>(n,0));
	    int ans=INT_MAX;
	    
	    q.push({indi,indj,0});
	    vis[indi][indj]=1;
	    
	    while(!q.empty()){
	        auto top = q.front();
	        q.pop();
            if(top[0] == tari && top[1] == tarj)
                ans = min(ans,top[2]);
	        for(auto m:moves){
	            int x = top[0]+m.first, y = top[1]+m.second;
	            if(x>=0 && x<n && y>=0 && y<n){
    	            if(!vis[x][y]){
                        vis[x][y]=1;
                        q.push({x,y,top[2]+1});
    	            }
	            }
	        }
	    }
	    return ans;
	}

    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        unordered_map<Node*,Node*> mp;
        stack<Node*> st;
        st.push(node);
        mp[node] = new Node(node->val);

        while(!st.empty()){
            Node* top = st.top();
            st.pop();
            for(auto i:top->neighbors){
                if(mp.find(i) == mp.end()){
                    st.push(i);
                    mp[i] = new Node(i->val);
                }
                mp[top]->neighbors.push_back(mp[i]);
            }
        }
        return mp[node];
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        queue<pair<int,int>> q;
        vector<pair<int,int>> moves = {{0,-1},{0,1},{-1,0},{1,0}};

        q.push(make_pair(sr,sc));
        visited[sr][sc]=1;

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            for(auto mv:moves){
                int x = top.first + mv.first, y = top.second + mv.second;
                if(x>=0 && x<m && y>=0 && y<n && !visited[x][y] && image[x][y] == image[sr][sc]){                    
                    visited[x][y]=1;
                    image[x][y]=color;
                    q.push(make_pair(x,y));
                }                
            }
        }
        image[sr][sc]=color;
        return image;        
    }

    //To find minimum number of cables from the graph need to be extracted to make all the computers connected.
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int comp=0, ex_edges=0;

        for(auto i:connections){
            if(ds.findPar(i[0]) == ds.findPar(i[1])) ex_edges++;
            else ds.UnionBySize(i[0], i[1]);
        }
        for(int i=0; i<n; i++)
            if(ds.parent[i] == i)
                comp++;  
                              
        comp--;
        return ex_edges >= comp? comp : -1;
    }

    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        auto it = find(wordList.begin(), wordList.end(), targetWord);
        if(it == wordList.end()) return 0;

        queue<pair<string,int>> q;
        unordered_set<string> st;
        int n = wordList.size();

        for(string s:wordList) st.insert(s);
        q.push(make_pair(startWord,1));

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            for(int i=0; i<top.first.size(); i++){
                string s = top.first;

                for(int j=97; j<=122; j++){
                    if(j==s[i]) continue;

                    s[i] = j;

                    if(st.find(s)!=st.end()){
                        q.push(make_pair(s,top.second+1));
                        st.erase(s);
                    }
                        
                    if(s == targetWord) return top.second+1;
                }
            }
        }
        return 0;
    }

    //Function to find the shortest distance of all the vertices from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s){
        queue<int> q;
        vector<int> dist(v,INT_MAX);        
        q.push(s);
        dist[s] = 0;
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for(auto i:adj[top]){
                if(dist[i[0]] > dist[top] + i[1]){
                    dist[i[0]] = dist[top] + i[1];
                    q.push(i[0]);
                }
            }
        }
        return dist;
    }

    //To find the minimum time taken by each job to be completed given by a Directed Acyclic Graph
    vector<int> minimumTime(int n,vector<vector<int>> &edges,int m){
        vector<int> indegree(n,0), ans(n,0);
        queue<int> q;
        vector<vector<int>> adj(n, vector<int>());
            
        for(auto i:edges){
            indegree[i[1]-1]++;
            adj[i[0]-1].push_back(i[1]-1);
        }
        
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
                ans[i] = 1;
            }
        }
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(int i:adj[top]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                    ans[i] = ans[top]+1;
                }
            }
        }
        return ans;
    }

    //Is it possible to finish all tasksGiven the total number of tasks N and a list of prerequisite pairs P
    bool prerequisiteTasks(int n, vector<pair<int, int> >& prerequisites) {
	    vector<int> indegree(n,0);
	    queue<int> q;
	    vector<int> topo;
	    vector<vector<int>> adj(n,vector<int>());
	    
	    for(auto i:prerequisites){
	        indegree[i.first]++;
	        adj[i.second].push_back(i.first);
	    }
	    
	    for(int i=0; i<n; i++)
	        if(!indegree[i])
	            q.push(i);
	   
	    while(!q.empty()){
	        int top = q.front();
	        q.pop();
	        topo.push_back(top);
	        
	        for(int i:adj[top]){
	            indegree[i]--;
	            if(indegree[i] == 0)
	                q.push(i);
	        }
	    }	    
	    return topo.size() == n;
	}

    //Given a grid of size n*m consisting of '0's (Water) and '1's(Land),ind the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,1},{1,-1}};
        int count=0;
        queue<pair<int,int>> q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    q.push({i,j});
                    visited[i][j]=1;
                    count++;
                    while(!q.empty()){
                        auto top = q.front();
                        q.pop();
                        int x = top.first, y = top.second;
                        for(auto i:dir){
                            int row = x + i.first, col = y + i.second;
                            if(row>=0 && row<m && col>=0 && col<n ){
                                if(!visited[row][col] && grid[row][col]=='1'){
                                    visited[row][col]=1;
                                    q.push({row,col});
                                }
                            }
                        }
                    }
                }
            }
        }
        return count;
    }

    //Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. 
    //Find the order of characters in the alien language.
    string findOrderAlienDict(string dict[], int n, int k) {
        vector<vector<int>> adj(k,vector<int>());
        string ans="";
        
        for(int i=0; i<n-1; i++){            
            if(dict[i][0] != dict[i+1][0]){
                adj[dict[i][0]-'a'].push_back(dict[i+1][0]-'a');
                continue;
            }            
            for(int j=1; j<min(dict[i].size(), dict[i+1].size()); j++){
                if(dict[i][j] != dict[i+1][j]){
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(k,adj);
        for(int i:topo) ans+= char(i+'a');    
        return ans;
    }

    //Given a weighted, undirected and connected graph, find the Minimum Spanning Tree and sum of the weights of the edges.
    //Using Prim's Algorithm
    vector<pair<int,int>> primSpanningTree(int v, vector<vector<vector<int>>> adj)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<bool> visited(v,0);
        vector<pair<int,int>> MST;
        int sum=0;
        
        pq.push({0,0,-1});
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int node = top[1];
            int wt = top[0];
            int par = top[2];
            
            if(visited[node]) continue;
            
            visited[node]=1;
            sum+= wt;
            if(par != -1) MST.push_back({node,par});
            
            for(auto i:adj[node]){
                int adj_node = i[0];
                int adj_wt = i[1];
                if(!visited[adj_node])
                    pq.push({adj_wt, adj_node, node});
            }
        }
        cout<<"Sum of edges: "<<sum<<endl;
        // return sum;
        return MST;
    }

    //Given a weighted, undirected and connected graph, find the Minimum Spanning Tree and sum of the weights of the edges.
    //Using Kruskal's Algorithm
    vector<pair<int,int>> kruskalSpanningTree(int v, vector<vector<vector<int>>> adj)
    {
        vector<vector<int>> edges(v,vector<int>(3));
        
        for(int i=0; i<v; i++){
            for(auto edg:adj[i]){
                edges.push_back({edg[1],i,edg[0]});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        vector<pair<int,int>> MST;
        DisjointSet ds(v);
        int MST_Wt=0;        
        
        for(auto i: edges){
            if(ds.findPar(i[1]) != ds.findPar(i[2])){
                ds.UnionBySize(i[1],i[2]);
                MST_Wt += i[0];
                MST.push_back({i[1],i[2]});
            }
        }
        cout<<"Sum of edges: "<<MST_Wt<<endl;
        // return MST_Wt;
        return MST;
    }

    //Find the shortest distances between every pair of vertices in a given edge-weighted directed graph
    void FloydWarshall_shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == -1 )
                    matrix[i][j] = 1001;
            }
        }
	    for(int via=0; via<n; via++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
	            }
	        }
	    }
	    for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1001 )
                    matrix[i][j] = -1;
            }
        }
	}

    //Given a weighted directed graph with n nodes check if it contains a negative weight cycle or not.
    //Using Floyd Warshall Algorithm
    bool isNegativeWeightCycleFW(int n, vector<vector<int>>edges){
	    vector<vector<int>> cost(n,vector<int>(n,1e9));
	    
	    for(auto i:edges)
	        cost[i[0]][i[1]] = i[2];	        

	    for(int i=0; i<n; i++)
	        cost[i][i] = 0;	       
            
	    for(int via=0; via<n; via++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
	            }
	        }
	    }
	    for(int i=0; i<n; i++){
	        if(cost[i][i]<0)
	            return 1;
	    }	    
	    return 0;
	}

    //Given a weighted directed graph with n nodes check if it contains a negative weight cycle or not.
    //Using Bellman Ford Algorithm
    int isNegativeWeightCycleBF(int n, vector<vector<int>>edges){
	    vector<int> dist(n,1e9);
	    dist[0] = 0;
	    for(int i=0; i<n-1; i++){
	        for(auto e:edges){
	            if(dist[e[0]]<1e9){
	                dist[e[1]] = min(dist[e[1]], dist[e[0]] + e[2]);
	            }
	        }
	    }
	    for(auto e:edges){
            if(dist[e[1]] > dist[e[0]] + e[2]){
                return 1;
            }
        }
        return 0;
	}

    //Given a weighted, directed and connected graph, find the shortest distance of all the vertex's from the source vertex S.
    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int S) {
        vector<int> dist(n,1e8);
	    dist[S] = 0;
	    for(int i=0; i<n-1; i++){
	        for(auto e:edges){
	            if(dist[e[0]]<1e9){
	                dist[e[1]] = min(dist[e[1]], dist[e[0]] + e[2]);
	            }
	        }
	    }
	    for(auto e:edges){
            if(dist[e[1]] > dist[e[0]] + e[2]){
                return {-1};
            }
        }
        return dist;
    }

    //Given a matrix cost of size n complete a tour from the city 0 to all other cities such that you 
    //visit each city atmost once and then at the end come back to city 0 in min cost.
    int all_visited;
    vector<vector<int>> dp_tsp;
    int TSP(int mask, int pos, vector<vector<int>>cost){
        if(mask == all_visited) return cost[pos][0];        
        if(dp_tsp[mask][pos]!= -1) return dp_tsp[mask][pos];
        
        int ans = INT_MAX;
        
        for(int i=0; i<cost.size(); i++){
            if((mask & (1<<i)) == 0){
                int new_ans = cost[pos][i] + TSP(mask|(1<<i),i,cost);
                ans = min(ans,new_ans);
            }
        }
        return dp_tsp[mask][pos] = ans;
    }
    
    int total_cost(vector<vector<int>>cost){
        int n = cost.size();        
        dp_tsp.resize(pow(2,n),vector<int>(n,-1));
        all_visited = (1<<n)-1;        
        return TSP(1,0,cost);
    }

};

int main()
{
	Graph g;
	// g.addEdge(0, 1,4, 0);
	// g.addEdge(0, 7,8, 0);
	// g.addEdge(1, 7,11, 0);
	// g.addEdge(1, 2,8, 0);
	// g.addEdge(7, 8,7, 0);
	// g.addEdge(2, 8,2, 0);
	// g.addEdge(8, 6,6, 0);
	// g.addEdge(2, 5,4, 0);
	// g.addEdge(6, 5,2, 0);
	// g.addEdge(2, 3,7, 0);
	// g.addEdge(3, 3,14, 0);
	// g.addEdge(3, 4,9, 0);
	// g.addEdge(5, 4,10, 0);
	// g.addEdge(7, 6,1, 0);
	// g.print_adj();

    //cout<<g.minStepToReachTarget({1,1},{4,5},5);

    // vector<pair<int,int>> PMST = g.primSpanningTree(5, {{{1,2},{2,1}},{{0,2},{2,1}},{{0,1},{1,1},{4,2},{3,2}},{{2,2},{4,1}},{{2,2},{3,1}}});
	// for(int i=0; i<PMST.size(); i++)
    //  cout<<PMST[i].first<<" "<<PMST[i].second<<endl;

	return 0;
}