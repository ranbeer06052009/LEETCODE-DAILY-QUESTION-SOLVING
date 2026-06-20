class Solution {
private:
    pair<pair<long long,long long>,long long> dfs(int u,vector<vector<int>>& adj,vector<int>& b){
        long long lt=-1e18, el=1e18;
        int cnt=0;
        for(int v:adj[u]){
            cnt++;
            pair<pair<long long,long long>,long long> res=dfs(v,adj,b);
            //long long ft=(res.first+(res.first-res.second)+b[v]);
            lt=max(lt,res.second);
            el=min(el,res.second);
        }
        if(cnt==0){
            return {{b[u],b[u]},b[u]};
        }
        long long ft=(lt-el)+b[u]+lt;
        return {{lt,el},ft};
    }
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);
        for(int i=0; i<n-1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        pair<pair<long long,long long>,long long> help=dfs(0,adj,baseTime);
        long long ans=help.second;
        return ans;
    }
};
