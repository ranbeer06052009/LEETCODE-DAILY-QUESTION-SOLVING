class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++) sum+=nums[i];
        if(sum%2!=0) return false;
        int k= sum/2;
        vector<bool> prev(k+1,0), cur(k+1,0);
        prev[0]=cur[0]=true;
        if(nums[0]<=k)prev[nums[0]]=true;
        for(int i=1; i<nums.size();i++){
            for(int targ=1; targ<=k; targ++){
                bool notTake= prev[targ];
                bool take= false;
                if(targ>= nums[i]) take= prev[targ-nums[i]];
                cur[targ]=take|notTake;
            }
            prev= cur;
        }
        return prev[k];
    }
};
