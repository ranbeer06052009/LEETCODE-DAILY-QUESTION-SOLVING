class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0, count=0,i;
        for(i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            else {
                if(max<count)max=count;
                count=0;
            }
        }
        if(max<count)return count;
        else return max;
    }
};
