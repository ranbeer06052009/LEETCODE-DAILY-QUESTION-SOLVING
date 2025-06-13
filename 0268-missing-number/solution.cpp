class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i,k=nums.size()+1;
        vector<int> m(k,-1);
        
        for(i=0;i<nums.size();i++){
            m[nums[i]]=nums[i];
        }
        for(i=0;i<=nums.size();i++){
            if(m[i]==-1) return i;
        }
        return 0;
}
};
