#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    unordered_map<int, list<pair<int,int>>> adjlist;

    void addEdge(int u, int v, int dist, bool undirected = 1){
        adjlist[u].push_back(make_pair(v,dist));
        if(undirected)
            adjlist[v].push_back(make_pair(u,dist));
    }

    void print_adj(){
        for(auto i : adjlist){
            cout<<i.first<<" : ";
            for(auto j : i.second){
                cout<<"( "<<j.first<<" , "<<j.second<<" ) ";
            }
            cout<<endl;
        }
    }

    bool CycleDetection(){}
    
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