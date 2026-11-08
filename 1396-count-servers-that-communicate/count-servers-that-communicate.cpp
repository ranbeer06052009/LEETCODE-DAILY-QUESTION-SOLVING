class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<bool> col(n,false),row(m,false);
        for(int i=0;i<m;i++){
            int cur=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)cur++;
            }
            if(cur>1)row[i]=true;
        }
        for(int j=0;j<n;j++){
            int cur=0;
            for(int i=0;i<m;i++){
                if(grid[i][j]==1)cur++;
            }
            if(cur>1)col[j]=true;
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((row[i]||col[j])&&grid[i][j]==1)ans++;
            }
        }
        return ans;
    }
};