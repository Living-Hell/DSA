#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> size, rank, parent;
public:
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

int main()
{
    DisjointSet ds(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);

    //To check if 3 and 7 belong to the same component
    if(ds.findPar(3) == ds.findPar(7)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    ds.UnionBySize(3,7);

    //To check if 3 and 7 belong to the same component
    if(ds.findPar(3) == ds.findPar(7)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}