class Solution {
public:
    long long f(int i, int k, vector<int>& nums,vector<long long>&dp){
        int n=nums.size();
        if(i==n)return 0;
        if(dp[i]!=-1) return dp[i];
        long long maxans=INT_MIN;
        int maxi=INT_MIN;
        int len=0;
        for(int j=i; j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,nums[j]);
            long long sum= len*maxi+f(j+1,k,nums,dp);
            maxans=max(maxans,sum);
        }
        return dp[i]=maxans;
    }
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n= nums.size();
        vector<long long> dp(n+1, 0);
        // return f(0,k,nums,dp);

        for(int i=n-1; i>=0; i--){
            long long maxans=INT_MIN;
            int maxi=INT_MIN;
            int len=0;
            for(int j=i; j<min(n,i+k);j++){
                len++;
                maxi=max(maxi,nums[j]);
                long long sum= len*maxi+dp[j+1];
                maxans=max(maxans,sum);
            }
            dp[i]=maxans;
        }
        return dp[0];
    }
};
