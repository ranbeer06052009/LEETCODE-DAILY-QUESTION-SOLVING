class Solution {
public:
    void dfs1(int u, vector<int> &p, string &s,vector<vector<int>> &adj,vector<int> &ls){
        int c=s[u]-'a', old=ls[c];

        if(u>0&&old!=-1)p[u]=old;
        ls[c]=u;
        for(int v: adj[u]){
            dfs1(v,p, s, adj, ls);
        }
        ls[c]=old;
    }

    int dfs2(int u, vector<vector<int>> &adj, vector<int> &ans){
        ans[u]=1;
        for(int v:adj[u]){
            ans[u]+=dfs2(v,adj,ans);
        }
        return ans[u];
    }
    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        int n=p.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[p[i]].push_back(i);
        }
        vector<int> ls(26,-1);

        dfs1(0,p,s, adj,ls);
        vector<int> ans(n,0);
        vector<vector<int>> adj1(n);
        for(int i=1;i<n;i++){
            adj1[p[i]].push_back(i);
        }
        dfs2(0,adj1,ans);
        return ans;
    }
};