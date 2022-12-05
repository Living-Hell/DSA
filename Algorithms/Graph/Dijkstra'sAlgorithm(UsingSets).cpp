//Alternate Name for Dijkstra's Algorithm - Uniform Cost Search and it is a kind of Best First Search

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source){

    //Create adjacency List
    unordered_map<int, list<pair<int,int>>> adj;

    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //Create distance array with infinite value initially
    vector<int> dist(vertices);

    for(int i=0; i<vertices; i++)
        dist[i] = INT_MAX;
    
    //Creation of set on the basis (distance, node)
    set<pair<int,int>> st;

    //Initialise distance and set with source node
    st.insert(make_pair(0,source));

    while(!st.empty()){

        //Fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //Remove top record now
        st.erase(st.begin());

        //Traverse on neighbours
        for(auto neighbour: adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                //If record found, erase it
                if(record != st.end()){
                    st.erase(record);
                }

                //Distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;

                //record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}