class Solution {
public:
    int f(int ind, int wt, vector<vector<int>> &dp, vector<int>& coins){
        if(ind==0){
            if(wt%coins[0]==0) return wt/coins[0];
            return 1e9;
        }
        if(dp[ind][wt]!=-1) return dp[ind][wt];
        int notT= 0+ f(ind-1, wt,dp,coins);
        int take= INT_MAX;
        if(wt>=coins[ind]) take=1+f(ind, wt-coins[ind], dp, coins);
        return dp[ind][wt]=min(take, notT);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        int ans=f(n-1,amount, dp, coins);
        if(ans>=1e9) return -1;
        return ans;
    }
};
