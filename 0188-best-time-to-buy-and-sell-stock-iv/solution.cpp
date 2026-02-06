class Solution {
private:
long f(int ind, int trans,int k, vector<vector<int>> &dp, int n, vector<int> &prices){
    if(ind==n||trans==2*k) return 0;
    if(dp[ind][trans]!=-1) return dp[ind][trans];
    long profit=0;
    if(trans%2==0){
        profit= max(-prices[ind]+f(ind+1,trans+1,k,dp,n,prices), 0+f(ind+1,trans,k,dp,n,prices));
    }
    else profit= max(prices[ind]+f(ind+1,trans+1,k,dp,n,prices), 0+f(ind+1,trans,k,dp,n,prices));
    return dp[ind][trans]=profit;
}
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        return f(0,0,k,dp,n,prices);
    }
};
