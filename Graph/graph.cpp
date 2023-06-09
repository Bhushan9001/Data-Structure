#include "bits/stdc++.h"
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>> adj;
    void addEdge(int u , int v, bool dir){
        //0->undirected
        //1->directed
        // create edge for u -> v
        adj[u].push_back(v);
        if(!dir)adj[v].push_back(u);
    }

    void print(){
        for(auto i: adj){
            cout<<i.first<<"-> ";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    int n , m;
    cout<<"Enter no. of nodes"<<endl;
    cin>>n;
    cout<<"enter no. of edges"<<endl;
    cin>>m;
    graph g;
    for (int i = 0; i < m; i++)
    {
        int u,v;

        cin>>u>>v;

        g.addEdge(u,v,0);
    }

    g.print();
    

return 0;
}