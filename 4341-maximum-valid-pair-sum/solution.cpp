class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ml=0;
        vector<int> m(n+1,0);
        for(int i=n-1; i>=0; i--){
            m[i]=max(m[i+1],nums[i]);
        }
        for(int i=0; i<n-k; i++){
            ml=max(ml,(long long)(nums[i]+m[i+k]));
        }
        return ml;
    }
};
