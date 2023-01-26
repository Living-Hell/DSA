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
    
    vector<int> BFS(){}

    vector<int> DFS(){}

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