#include<bits/stdc++.h>
using namespace std;
 
 
void dfs(vector<vector<int>> matrix,vector<vector<bool> > &visited, vector<vector<int> > &dp, int i,int j,int m,int n){
	visited[i][j]=1;
	int cnt=0;
	int dx[]={0,0,1,-1};
	int dy[]={1,-1,0,0};
	for(int k=0;k<4;k++){
	    int nx=i+dx[k];
	    int ny=j+dy[k];
	    if(nx>=0 and ny>=0 and nx<m and ny<n and matrix[nx][ny]>matrix[i][j]){
	        if(visited[nx][ny])cnt=max(cnt,1+dp[nx][ny]);
	        else{
	            dfs(matrix,visited,dp,nx,ny,m,n);
	            cnt=max(cnt,1+dp[nx][ny]);
	        }
	    }
	}
	dp[i][j]=cnt;
	return;
	
}
 
int longestPathSequence(vector<vector<int>> matrix) {
  // Write your code here.
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<bool> > visited(m+1,vector<bool>(n+1,0));
	vector<vector<int> > cache(m+1,vector<int>(n+1,0));
	//do a dfs from every cell //and store the length of of maximum len seq startinf from that cell
	int ans = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dfs(matrix,visited,cache,i,j,m,n);
			ans = max(ans,cache[i][j]);
		}
	}
	return ans+1;
};
int main(){
    vector<vector<int>>matrix={{0,2,4,3,2},
                               {7,6,5,5,1},
                               {8,9,7,18,14},
                               {5,10,11,12,13}
                               
    };
    cout<<longestPathSequence(matrix);
}
