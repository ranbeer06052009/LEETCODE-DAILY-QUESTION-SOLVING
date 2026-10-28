class Solution {
public:
    // void f(int i,int j, int cur, int &ans, vector<vector<int>> &a, int m, int n){
    //     cur^=a[i][j];
    //     if((i==m-1)&&(j==n-1)){
    //         ans=min(ans,cur);
    //         //cur=0;
    //         return ;
    //     }

    //     if(i<m-1){
    //         f(i+1,j,cur,ans,a,m,n);
    //     }
    //     if(j<n-1){
    //         f(i,j+1,cur,ans,a,m,n);
    //     }

    // }
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> dp(n, vector<bool>(1024, false));
        dp[0][grid[0][0]] = true;
        for (int j = 1; j < n; ++j) {
            for (int val = 0; val < 1024; ++val) {
                if (dp[j - 1][val]) {
                    dp[j][val ^ grid[0][j]] = true;
                }
            }
        }
        for(int i=1;i<m;i++){
            vector<vector<bool>> ndp(n,vector<bool>(1024,false));
            for(int j=0;j<n;j++){
                for(int val=0;val<1024;val++){
                    if(dp[j][val]||(j>0&&ndp[j-1][val])){
                        ndp[j][val^grid[i][j]]=true;
                    }
                }
            }
            dp=move(ndp);
        }
        int ans=0;
        for (int val = 0; val < 1024; ++val) {
            if (dp[n - 1][val]) {
                return val;
            }
        }
        return ans;
    }
};