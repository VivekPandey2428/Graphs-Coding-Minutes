#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int>*l;
    public:
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }
    void addedge(int a,int b){
        l[a].push_back(b);
        l[b].push_back(a);
    }
    void depthfs(int source,bool *visited){
        visited[source]=true;
        cout<<source<<" ";
        for(auto nbrs:l[source]){
            if(!visited[nbrs]){
            depthfs(nbrs,visited);
            }
        }
        return;
    }
    void dfs(int source){
        bool *visited=new bool[V]{false};
        depthfs(source,visited);
    }
};
int main() {
    Graph g(10);
    g.addedge(1,2);
    g.addedge(1,0);
    g.addedge(2,3);
    g.addedge(3,5);
    g.addedge(0,4);
    g.addedge(4,5);
    g.addedge(5,6);
    g.dfs(4);
}
