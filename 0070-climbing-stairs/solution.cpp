class Solution {
private:
    int func(int n,vector<int>&dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=func(n-1,dp)+func(n-2,dp);
    }
public:
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
        int prev2=0, prev=1;
        for(int i=1; i<=n; i++){
            int cur= prev+prev2;
            prev2= prev;
            prev=cur;
        }
        return prev;
        // return func(n);
    }
};
