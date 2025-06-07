class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =1;
        // int ele= nums[0];
        for(int j=1;j<nums.size();j++)
        {
            if(i==1 || nums[i-2] != nums[j])
            {
                nums[i] = nums[j];
                i++;
            }
        }
    return i ; 
    }
};
