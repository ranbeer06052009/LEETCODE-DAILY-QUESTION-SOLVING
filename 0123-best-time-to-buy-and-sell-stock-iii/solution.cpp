class Solution {
private:
    long f(int ind, int buy, vector<int>& prices, int n, vector<vector<vector<int>>> &dp,int cap){
        if(ind==n||cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        long profit=0;
        if(buy){
            profit=max(-prices[ind]+f(ind+1,0,prices,n,dp,cap),0+f(ind+1,1,prices,n,dp,cap));
        }
        else{
            profit=max(prices[ind]+f(ind+1,1,prices,n,dp,cap-1),0+f(ind+1,0,prices,n,dp,cap));
        }

        return dp[ind][buy][cap]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int> (3,-1)));
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int> (3,0)));
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    if(buy){
                        dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                    }
                    else{
                        dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                    }
                }
            }
        }
        // return f(0,1,prices,n,dp,2);
        return dp[0][1][2];
    }
};
