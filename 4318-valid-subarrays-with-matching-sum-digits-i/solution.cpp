class Solution {
public:
    int first(unsigned long long n){
        int d=log10(n);
        return (int)(n/pow(10,d));
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        vector<unsigned long long> pref(n+1,0LL);
        for(int i=0; i<n; i++){
            pref[i+1]=pref[i]+nums[i];
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                unsigned long long sum=pref[j+1]-pref[i];
                
                if(sum%10==x&&x==first(sum))cnt++;
            }
        }
        return cnt;
    }
};
