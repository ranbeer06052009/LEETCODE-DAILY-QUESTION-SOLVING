class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> minL(n,0),maxR(n,0);
        minL[0]=nums[0];
        for(int i=1; i<n; i++){
            minL[i]=min(minL[i-1],nums[i]);
        }
        maxR[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            maxR[i]=max(maxR[i+1],nums[i]);
        }
        for(int i=1; i<n-1;i++){
            if(nums[i]>minL[i-1]&&nums[i]<maxR[i+1]){
                return true;
            }
        }
        return false;
    }
};