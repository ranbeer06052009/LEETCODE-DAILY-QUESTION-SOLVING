class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=1;
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                bool pos=true;
                for(int k=0;k<m;k++){
                    if(abs(grid[k][i]-grid[k][j])>limit){
                        pos=false;
                        break;
                    }
                }
                if(pos){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};