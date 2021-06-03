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
    bool dfs(int node,vector<bool>&visited,int parent){
        visited[node]=true;
        for(auto nbr:l[node]){
            if(!visited[nbr]){
                bool x=dfs(nbr,visited,node);
                if(x)return true;
            }
            else if(nbr!=parent){
                return true;
            }
        }
        return false;
    }
    bool contain_cycle(){
        vector<bool>visited(V,false);
        return dfs(0,visited,-1);
    }
    
};
int main() {
    Graph g(2);
    g.addedge(1,2);
    cout<<g.contain_cycle();
}
