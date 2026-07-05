class Solution {
public:
    int f(int n){
        int minm=11,maxm=-1;
        while(n>0){
            int x=n%10;
            minm=min(minm,x);
            maxm=max(maxm,x);
            n/=10;
        }
        return maxm-minm;
    }
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        int maxm=-1;
        for(int i=0; i<n; i++){
            maxm=max(maxm,f(nums[i]));
        }
        long long ans=0;
        for(int i=0; i<n; i++){
            if(f(nums[i])==maxm)ans+=nums[i];
        }
        return ans;
    }
};
