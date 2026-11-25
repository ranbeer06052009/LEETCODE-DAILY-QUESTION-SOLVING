class Solution {
public:
    bool check(int mid, vector<int> &v,int n){
        const uint64_t BASE = 1315423911ULL; // Random odd prime base
        uint64_t h = 0, p = 1;
        
        for (int i = 0; i < mid - 1; i++) p *= BASE;
        for (int i = 0; i < mid; i++) h = h * BASE + (uint64_t)v[i];

        unordered_map<uint64_t, int> mp;
        mp[h]++;

        for (int i = mid; i < n; i++) {
            h = (h - (uint64_t)v[i - mid] * p) * BASE + (uint64_t)v[i];
            mp[h]++;
        }

        for (auto& [k, cnt] : mp) {
            if (cnt == 1) return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=1,r=n,ans=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,nums,n)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};