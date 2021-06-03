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
    }
    bool dfs(int node,vector<bool>&visited,vector<bool>&stack){
        visited[node]=true;
        stack[node]=true;
        for(auto nbr:l[node]){
            if(stack[nbr]==true){
                return true;
            }
            else if(!visited[nbr]){
                bool x=dfs(nbr,visited,stack);
                if(x)return true;
            }
        }
        stack[node]=false;
        return false;
    }
    bool contain_cycle(){
        vector<bool>visited(V,false);
        vector<bool>stack(V,false);
        return dfs(0,visited,stack);
    }
    
};
bool iscycle(int V,vector<pair<int,int>>edges){
    Graph g(V);
    for(auto edge:edges){
        g.addedge(edge.first,edge.second);
    }
    return g.contain_cycle();
}
int main() {
    Graph g(4);
    vector<pair<int,int>>v;
    v.push_back({0,1});
    v.push_back({1,2});
    v.push_back({2,3});
    cout<<iscycle(4,v);
}
