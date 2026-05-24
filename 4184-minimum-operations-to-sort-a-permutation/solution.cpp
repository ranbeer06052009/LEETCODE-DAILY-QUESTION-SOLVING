class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(int j=0; j<n; j++){
            if(nums[j]==0){
                i=j;
                break;
            }
        }
        int ans=-1;
        bool flag1=true;
        for(int k=0; k<n; k++){
            if(nums[(i+k)%n]!=k){
                flag1=false;
                break;
            }
        }
        if(flag1){
            int ct1=i;
            int ct2=n-i+2;
            ans=min(ct1,ct2);
        }
        bool flag2=true;
        for(int k=0; k<n; k++){
            if(nums[(i-k+n)%n]!=k){
                flag2=false;
                break;
            }
        }
        if(flag2){
             int ct1=i+2;
             int ct2=n-i;
             int cost=min(ct1,ct2);
             if(ans==-1){
                 ans=cost;
             }else{
                 ans=min(ans,cost);
             }   
        }
        return ans;
    }    
};
