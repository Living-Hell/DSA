//Function to return list containing vertices of a 
//Directed Acyclic Graph (DAG) in Topological order. 

vector<int> topoSort(int v, vector<int> adj[]) {
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