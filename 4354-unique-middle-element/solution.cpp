class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size();
        int i=nums[n/2];
        for(int j=0; j<n; j++){
            if(nums[j]==i &&j!=(n/2)){
                return false;
            }
        }
        return true;
    }
};
