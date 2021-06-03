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
    void bfs(int source,int dest){
        queue<int>q;
        q.push(source);
        bool *visited=new bool[V]{false};
        int *dist=new int[V]{0};
        int *parent=new int[V]{0};
        visited[source]=true;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            cout<<f<<"-->";
            for(auto nbrs:l[f]){
                if(!visited[nbrs]){
                q.push(nbrs);
                parent[nbrs]=f+1;
                dist[nbrs]=dist[f]+1;
                visited[nbrs]=true;
                }
            }
        }
        for(int i=0;i<V;i++){
            cout<<dist[i]<<" ";
        }

    }
};
int main() {
    Graph g(4);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.bfs(0,3);
}
