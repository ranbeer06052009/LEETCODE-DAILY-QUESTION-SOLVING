class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans,maxl(n,0),maxr(n,0);
        ans.push_back(nums[0]);
        maxl[0]=nums[0],maxr[n-1]=nums[n-1];
        // int lmax=nums[0],rmax=nums[n-1];
        for(int i=1; i<n; i++){
            if(nums[i-1]>maxl[i-1]){
                // lmax=nums[i];
                maxl[i]=nums[i-1];
            }
            else maxl[i]=maxl[i-1];
        }
        if(n==1||n==2)return nums;
        for(int i=n-2; i>=0; --i){
            if(nums[i+1]>maxr[i+1]){
                // rmax=nums[i];
                maxr[i]=nums[i+1];
            }
            else maxr[i]=maxr[i+1];
        }
        for(int i=1; i<n; i++){
            if(i==n-1){ans.push_back(nums[n-1]);break;}
            if((nums[i]>maxl[i])||nums[i]>maxr[i]){
                ans.push_back(nums[i]);
            }
        }
        // if(ans[ans.size()-1]!=nums[n-1]||ans.size()==1)ans.push_back(nums[n-1]);
        // // for(int i=1; i<n; i++){
        // //     cout<<maxl[i]<<" "<<maxr[i];
        // // }
        return ans;
    }
};
