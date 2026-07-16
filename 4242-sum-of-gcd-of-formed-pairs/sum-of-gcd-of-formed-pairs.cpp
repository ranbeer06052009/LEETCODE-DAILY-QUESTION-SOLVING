class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefs(n+1,0);
        for(int i=0; i<n; i++){
            prefs[i+1]=max(prefs[i],(long long)nums[i]);
        }
        vector<long long>pref(n+1,0);
        for(int i=0; i<n; i++){
            pref[i+1]=gcd(prefs[i+1],nums[i]);
        } 
        sort(pref.begin()+1,pref.end());
        int m=pref.size();
        long long ans=0;
        for(int i=1;i<=m/2;i++){
            if(i!=m-i){
                ans+=gcd(pref[i],pref[m-i]);
            }
        }
        return ans;
    }
};