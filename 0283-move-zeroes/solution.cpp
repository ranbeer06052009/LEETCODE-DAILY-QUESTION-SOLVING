class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j;
        for(i=0;i<nums.size();i++){
            if(nums[i]==0){
                for(j=i+1;j<nums.size();j++){
                   if(nums[j]!=0){
                     nums[i]=nums[j];
                     nums[j]=0;
                     break;
                }                
            }
        }
    }
}};
