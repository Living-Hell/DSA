#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    unordered_map<int, list<pair<int,int>>> adjlist;

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
	
	return 0;
}