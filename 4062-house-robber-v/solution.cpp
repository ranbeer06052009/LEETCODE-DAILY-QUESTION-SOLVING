class Solution {
// long long f(int i,vector<int>& nums,vector<int>& colors){
//     if (i>=n) return 0;
//     if(dp[i]!=-1) return dp[i];
//     long long int pick = nums[i];
//     if (i > 1&&colors[i]!=colors[i-1]) pick += dp[i-2];

//     long long int nonPick = prev;

//     long long int ans = max(pick, nonPick);
//     return dp[i]=ans;
// }
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        long long ans = 0;
        int l = 0;
        int j = 0;
        int prevcol = colors[0];
        long long s1, s2;
        int n = nums.size(), i=0;

        for(i=1; i<n; i++){
            if(colors[i] == prevcol){
                continue;
            }
            else{
                s1 = 0, s2 = 0;

                for(int k=l; k<i; k+=2)  s1 += nums[k];
                for(int k=l+1; k<i; k+=2)  s2 += nums[k];

                ans += max(s1, s2);
                l = i;
                prevcol = colors[i];
            }
        }

        s1 = 0, s2 = 0;
        for(int k=l; k<i; k+=2)  s1 += nums[k];
        for(int k=l+1; k<i; k+=2)  s2 += nums[k];

        ans += max(s1, s2);

        return ans;
    }
};
