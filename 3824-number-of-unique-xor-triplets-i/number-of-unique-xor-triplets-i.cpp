class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n; i++){
            ans|=nums[i];
        }
        return (n<=2)?n:ans+1;
    }
};