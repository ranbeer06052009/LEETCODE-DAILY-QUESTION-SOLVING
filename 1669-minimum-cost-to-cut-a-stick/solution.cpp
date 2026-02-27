class Solution {
public:
    long long f(int l, int r, vector<int>& cuts,vector<vector<int>> &dp){
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        long long ans=1e9;
        for(int i= l; i<=r; i++){
            ans= min(cuts[r+1]-cuts[l-1]+f(l,i-1,cuts,dp)+f(i+1,r,cuts,dp),ans);
        }
        return dp[l][r]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int m= cuts.size();
        vector<int> newcuts(m+2);
        for(int i=1; i<=m; i++) newcuts[i]=cuts[i-1];
        newcuts[0]=0;
        newcuts[m+1]=n;
        sort(newcuts.begin(),newcuts.end());
        vector<vector<int>>dp(m+2,vector<int>(m+2,-1));
        return f(1,m,newcuts,dp);
    }
};
