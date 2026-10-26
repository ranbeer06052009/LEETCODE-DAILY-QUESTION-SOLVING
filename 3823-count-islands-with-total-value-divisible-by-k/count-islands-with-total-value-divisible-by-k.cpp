class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis,int m,int n,long long &sum){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0||vis[i][j]==1){
            return ;
        }
        sum+=grid[i][j];
        vis[i][j]=1;
        dfs(i+1,j,grid,vis,m,n,sum);
        dfs(i,j+1,grid,vis,m,n,sum);
        dfs(i-1,j,grid,vis,m,n,sum);
        dfs(i,j-1,grid,vis,m,n,sum);
        return;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==1||grid[i][j]==0)continue;
                long long sum=0;
                dfs(i,j,grid,vis,m,n,sum);
                if(sum%k==0)cnt++;
            }
        }
        return cnt;
    }
};