class Solution {
public:
    const 
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),[](const auto &a, const auto &b){
            return a[1]<b[1];
        });
        vector<pair<int,int>>q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        vector<int> cnt(n+1),ans(q.size());
        int l=0,r=0,act=0;
        for(auto[t,i]:q){
            while(r<logs.size()&&logs[r][1]<=t){
                cnt[logs[r][0]]++;
                if(cnt[logs[r][0]]==1)act++;
                r++;
            }
            while(l<r&&logs[l][1]<t-x){
                cnt[logs[l][0]]--;
                if(cnt[logs[l][0]]==0)act--;
                l++;
            }
            ans[i]=n-act;
        }
        return ans;
    }
};