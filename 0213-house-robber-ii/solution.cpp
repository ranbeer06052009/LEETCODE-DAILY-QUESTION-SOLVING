class Solution {
public:
    int maxrob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        for(int i=1; i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=dp[i-2];
            int notpick=0+dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> temp1(n),temp2(n);
        for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        if(n==1)return nums[0];
        return max(maxrob(temp1),maxrob(temp2));
    }
};
