class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int minm=prices[0];
        int ans=0;
        for(int i=1; i<n; i++){
           int profit=prices[i]-minm;
           ans=max(ans,profit);
           minm= min(minm, prices[i]);
        }
        return ans;
    }
};
