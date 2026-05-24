class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int>a;
        int n=nums.size();
        // b.push_back(nums[0]);
        // for(int i=1; i<n;i++){
        //     if(nums[i]!=nums[i-1])b.push_back(a[i]);
        // }
        int cnt=1;
        a.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if((nums[i]==nums[i-1])&&cnt+1<=k){
                cnt++;
                a.push_back(nums[i]);
            }
            else if(nums[i]!=nums[i-1]){
                cnt=1;
                a.push_back(nums[i]);
            }else{
                continue;
            }
        }
        return a;
    }
};
