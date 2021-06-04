#include<bits/stdc++.h>
#include<climits>
using namespace std;
class Graph{
    int V;
    list<pair<int,int>>*l;
    public:
    Graph(int V){
        this->V=V;
        l=new list<pair<int,int>>[V];
    }
    void addedge(int a,int b,int wt){
        l[a].push_back({wt,b});
        l[b].push_back({wt,a});
    }
    int bfs(int src,int dest){
        vector<int>dist(V,INT_MAX);
        set<pair<int,int>>s;
        dist[src]=0;
        s.insert({0,src});
        while(!s.empty()){
            auto it=s.begin();
            int node=it->second;
            int distance=it->first;
            s.erase(it);
            for(auto nbr:l[node]){
                int idxofnbr=nbr.second;
                int distofcurrentnode=nbr.first;
                if(distofcurrentnode+distance<dist[idxofnbr]){
                    auto temp=s.find({dist[idxofnbr],idxofnbr});
                    if(temp!=s.end())s.erase(temp);
                    dist[idxofnbr]=distofcurrentnode+distance;
                    s.insert({dist[idxofnbr],idxofnbr});
                }
            }
        }
        return dist[dest];
    }
};
int main(){
    Graph g(6);
    g.addedge(0,1,1);
    g.addedge(1,2,1);
    g.addedge(0,2,4);
    g.addedge(0,3,7);
    g.addedge(3,2,2);
    g.addedge(3,4,3);
    cout<<g.bfs(0,4);
}
