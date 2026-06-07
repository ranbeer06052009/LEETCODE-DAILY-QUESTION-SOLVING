class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n=nums.size();
        m=min(m,n/l);
        if(m==0)return 0;
        vector<long long> pref(n+1,0);
        for(int i=0; i<n; i++){
            pref[i+1]=pref[i]+nums[i];
        }
        const long long INF=1e15;
        vector<long long>dpp(n+1,0);
        long long ans=-INF;
        for(int j=1; j<=m; j++){
            vector<long long>dpc(n+1,-INF);
            vector<int> dq(n+1);
            int h=0,t=0;
            for(int i=1;i<=n; i++){
                int idx=i-l;
                if(idx>=0){
                    if(dpp[idx]>-INF/2){
                        long long v=dpp[idx]-pref[idx];
                        while(t>h&&dpp[dq[t-1]]-pref[dq[t-1]]<=v)t--;
                        dq[t++]=idx;
                    }
                }
                while(t>h&&dq[h]<i-r)h++;
                dpc[i]=dpc[i-1];
                if(t>h)dpc[i]=max(dpc[i],dpp[dq[h]]-pref[dq[h]]+pref[i]);
            }
            ans=max(ans,dpc[n]);
            dpp=dpc;
        }
        return ans;
    }
};
