class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int mn=INT_MAX;
        vector<int> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        for(int i=l;i<=r;i++){
            for(int j=i;j<=n;j++){
                int cur=pref[j]-pref[j-i];
                if(cur>0)mn=min(mn,cur);
                //cout<<pref[j]-pref[j-i]<<" ";
            }
        }
        return (mn==INT_MAX)?-1:mn;
    }
};