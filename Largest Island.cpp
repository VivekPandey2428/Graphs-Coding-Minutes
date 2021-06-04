#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int> >&grid,vector<vector<bool> >&visited,int i,int j,int m,int n){
    visited[i][j]=true;
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    int cs=1;
    for(int k=0;k<4;k++){
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(nx>=0 and nx<m and ny>=0 and ny<n and !visited[nx][ny]and grid[nx][ny]==1){
            cs+=dfs(grid,visited,nx,ny,m,n);
        }
    }
    return cs;
}
int largest_island(vector<vector<int> > grid){
    //return the size of largest island in grid
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    int largest=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && !visited[i][j]){
                int val=dfs(grid,visited,i,j,m,n);
                if(val>largest)largest=val;
            }
        }
    }
    return largest;
    
}
