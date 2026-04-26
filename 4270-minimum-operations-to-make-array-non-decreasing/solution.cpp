class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n=nums.size();
        long long maxm=0,minm=1e9+7,prev=nums[0],ans=0;
        // for(int i=0; i<n; i++){
        //     if(nums[i]>maxm){
        //         maxm=nums[i];
        //     }
        //     if(nums[i]<minm)minm=nums[i];
        // }
        int flag=0;
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]){
                ans+=(long long)(nums[i]-nums[i+1]);
            }
        }
        return ans;
    }
};
