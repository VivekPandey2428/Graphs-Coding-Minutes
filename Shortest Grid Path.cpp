#include<vector>
#include<set>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int x;
    int y;
    int dist;
    Node(int x,int y,int dist){
        this->x=x;
        this->y=y;
        this->dist=dist;
    }
};
class compare{
    public:
    bool operator()(Node a,Node b){
        return a.dist<=b.dist;
    }
};
int shortest_path(vector<vector<int> > grid){
    //return the shortest path len
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>dist(m+1,vector<int>(n+1,INT_MAX));
    set<Node,compare>s;
    dist[0][0]=grid[0][0];
    s.insert(Node(0,0,dist[0][0]));
    while(!s.empty()){
        auto it=s.begin();
        int i=it->x;
        int j=it->y;
        int prevdist=it->dist;
        s.erase(it);
        int dx[]={1,0,0,-1};
        int dy[]={0,1,-1,0};
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 and nx<m and ny>=0 and ny<n and prevdist+grid[nx][ny]<dist[nx][ny]){
                auto temp=Node(nx,ny,dist[nx][ny]);
                if(s.find(temp)!=s.end())s.erase(temp);
                dist[nx][ny]=prevdist+grid[nx][ny];
                s.insert(Node(nx,ny,dist[nx][ny]));
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return dist[m-1][n-1];
    
    
}
int main(){
    vector<vector<int>>dist={{31,100,65,12,18},
                             {10,13,47,157,6},
                             {100,113,174,11,33},
                             {88,124,41,20,140},
                             {99,32,111,41,20},
    };
    shortest_path(dist);
}
