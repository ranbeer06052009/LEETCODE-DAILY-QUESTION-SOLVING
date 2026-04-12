class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int cnt1=0, cnt0=0;
        for(int i=0;  i<n; i++){
            if(s[i]=='0')cnt0++;
            else cnt1++;
        }
        vector<int>p(n+1,0);
        for(int i=0; i<n; i++){
            p[i+1]=p[i]+(s[i]=='1'?1:-1);
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[p[i]].push_back(i);
        }
        int ans=0,prefix;
        for(int i=1; i<=n;i++){
            prefix=p[i];
            if(mp.count(prefix)&&mp[prefix].front()<i){
                ans=max(ans,i-mp[prefix].front());
            }
            if(mp.count(prefix-2)){
                int len=i-2*cnt0;
                auto &v=mp[prefix-2];
                auto it=lower_bound(v.begin(),v.end(),len);
                if(it!=v.end()&&*it<i)
                ans=max(ans,i-*it);
            }
            if(mp.count(prefix+2)){
                int len=i-2*cnt1;
                auto &v=mp[prefix+2];
                auto it=lower_bound(v.begin(),v.end(),len);
                if(it!=v.end()&&*it<i)
                ans=max(ans,i-*it);
            }
            //if(!mp.count(prefix))mp[prefix]=i;
        }
        return ans;
    }
};
