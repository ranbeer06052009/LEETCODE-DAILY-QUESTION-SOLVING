class Solution {
private:
    long f(int ind, int buy, vector<int>& prices, int n, vector<vector<int>> &dp,int fee){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        long profit=0;
        if(buy){
            profit=max(-prices[ind]+f(ind+1,0,prices,n,dp,fee),0+f(ind+1,1,prices,n,dp,fee));
        }
        else{
            profit=max(prices[ind]+f(ind+1,1,prices,n,dp,fee)-fee,0+f(ind+1,0,prices,n,dp,fee));
        }

        return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n= prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,n,dp,fee);
    }
};
