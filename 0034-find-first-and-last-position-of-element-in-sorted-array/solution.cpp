class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        int left=-1,right=-1;
        int flagl=false,flagr=false;
        while(l<=r){
            if(nums[l]==target && (!flagl)){
                flagl=true;
                left=l;
            }
            if(flagl){
                l--;
            }
            if(nums[r]==target && (!flagr)){
                flagr=true;
                right=r;
            }
            if(flagr){
                r++;
            }
            l++;r--;
            if(flagl && flagr) break;
        }
        return {left,right};
    }
};
